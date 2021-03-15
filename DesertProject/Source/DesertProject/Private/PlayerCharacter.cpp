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

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveLeft"), this, &APlayerCharacter::MoveLeft);
	PlayerInputComponent->BindAxis(TEXT("LookHorizontal"), this, &APlayerCharacter::LookHorizontal);
	PlayerInputComponent->BindAxis(TEXT("LookVertical"), this, &APlayerCharacter::LookVertical);


	PlayerInputComponent->BindAction(TEXT("PullTheTrigger"), EInputEvent::IE_Pressed, this, &APlayerCharacter::PullTheTrigger);
	//PlayerInputComponent->BindAction(TEXT("PullTheTrigger"), EInputEvent::IE_, this, &APlayerCharacter::PullTheTrigger);
	PlayerInputComponent->BindAction(TEXT("AimDownSight"), EInputEvent::IE_Pressed, this, &APlayerCharacter::AimDownSight);
}

void APlayerCharacter::initComponents()
{
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MAINCAMERA"));
	//FAttachmentTransformRules AttachmentTransforRules = FAttachmentTransformRules::SnapToTargetNotIncludingScale;
	MainCamera->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void APlayerCharacter::loadAsset()
{

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

void APlayerCharacter::PullTheTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}

void APlayerCharacter::AimDownSight()
{
	UE_LOG(LogTemp, Warning, TEXT("Sight"));
}

