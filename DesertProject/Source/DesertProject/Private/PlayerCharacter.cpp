// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Engine/EngineTypes.h"
#include "..\Public\PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	loadAsset();
	bAutoFireMode = false;
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (bAutoFireMode)
		UE_LOG(LogTemp, Warning, TEXT("Auto Fire"));*/


}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Axis input bind
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveLeft"), this, &APlayerCharacter::MoveLeft);
	PlayerInputComponent->BindAxis(TEXT("LookHorizontal"), this, &APlayerCharacter::LookHorizontal);
	PlayerInputComponent->BindAxis(TEXT("LookVertical"), this, &APlayerCharacter::LookVertical);

	//Action Input Bind
	PlayerInputComponent->BindAction(TEXT("PullTheTrigger"), EInputEvent::IE_Pressed, this, &APlayerCharacter::PullTrigger);
	PlayerInputComponent->BindAction(TEXT("PullTheTrigger"), EInputEvent::IE_Released, this, &APlayerCharacter::ReleaseTrigger);
	//PlayerInputComponent->BindAction(TEXT("PullTheTrigger"), EInputEvent::IE_, this, &APlayerCharacter::PullTheTrigger);
	PlayerInputComponent->BindAction(TEXT("AimDownSight"), EInputEvent::IE_Pressed, this, &APlayerCharacter::AimDownSight);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::initComponents()
{
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MAINCAMERA"));
	//FAttachmentTransformRules AttachmentTransforRules = FAttachmentTransformRules::SnapToTargetNotIncludingScale;
	MainCamera->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void APlayerCharacter::loadAsset()
{
	/*
	 *	Skeletal Mesh
	 *	
	 */
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SM_Arm(TEXT("SkeletalMesh'/Game/M4A4_Animated/Arms/Mesh/Mesh_Arms.Mesh_Arms'"));
	if(SM_Arm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_Arm.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90.0f));
		GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
		
	}


	
}

void APlayerCharacter::MoveForward(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
}

void APlayerCharacter::MoveLeft(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void APlayerCharacter::LookHorizontal(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

void APlayerCharacter::LookVertical(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}

void APlayerCharacter::PullTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
	//(bAutoFireMode) ? bAutoFireMode = false : bAutoFireMode = true;
}
void APlayerCharacter::ReleaseTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("Release"));
}
void APlayerCharacter::AimDownSight()
{
	UE_LOG(LogTemp, Warning, TEXT("Sight"));
	
}

void APlayerCharacter::Jump()
{
	Super::Jump();
	UE_LOG(LogTemp, Warning, TEXT("Jump"));
}

