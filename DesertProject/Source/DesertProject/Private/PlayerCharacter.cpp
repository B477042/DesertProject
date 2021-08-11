// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Engine/EngineTypes.h"
#include "Components/CapsuleComponent.h"
#include "FPSCharacterAnimInstance.h"
#include "WeaponBase.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	initComponents();
	loadAsset();
	bAutoFireMode = false;
	Tags.Add(TEXT("Player"));
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	//Camera Settings
	float X, Y, Z;
	MainCamera->SetRelativeLocation(FVector(X = -29.000000, Y = 2.000000, Z = 73.000000));
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this , &APlayerCharacter::OnCapsuleCompBeginOverlap);
}

void APlayerCharacter::OnCapsuleCompBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PickUpWeapon(OtherActor);
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
	
	PlayerInputComponent->BindAction(TEXT("AimDownSight"), EInputEvent::IE_Pressed, this, &APlayerCharacter::AimDownSight);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::PickUpWeapon(AActor* OtherActor)
{
	if (!OtherActor)
	{
		UE_LOG(LogTemp, Log, TEXT("nullptr"));
		return;
	}

	auto WeaponItem = Cast<AWeaponBase>(OtherActor);
	if (!WeaponItem)
	{
		UE_LOG(LogTemp, Log, TEXT("Casting Failed"));
		return;
	}

	//Attach Weapon to character
	AttachWeapon(WeaponItem);

}

void APlayerCharacter::initComponents()
{
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
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
		//GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
		
	}

	/*
	 *  Set AnimInstance
	 */
	static ConstructorHelpers::FClassFinder<UFPSCharacterAnimInstance>ANIM(TEXT("AnimBlueprint'/Game/MyFolder/Animation/AnimInstance/AnimInstance_PlayerArm.AnimInstance_PlayerArm_C'"));
	if (ANIM.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIM.Class);
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

void APlayerCharacter::AttachWeapon(AWeaponBase* NewWeapon)
{
	if (!NewWeapon)
	{
		UE_LOG(LogTemp, Log, TEXT("Nullptr"));
		return;
	}

	//Weapon Inventory Check
	//Implement later



	NewWeapon->PickedBy(this);
	//Attach Weapon
	NewWeapon->AttachToComponent(GetMesh() , FAttachmentTransformRules::SnapToTargetNotIncludingScale, Name_GripPoint);
	//Rotate and re-positioning Weapon Actor
	NewWeapon->SetActorRelativeLocation(FVector(0.0f,0.0,-1.9f));
	NewWeapon->SetActorRelativeRotation(FRotator(0.0f,90.0f,0.0f));



	UE_LOG(LogTemp, Error, TEXT("Attach!"));
}

