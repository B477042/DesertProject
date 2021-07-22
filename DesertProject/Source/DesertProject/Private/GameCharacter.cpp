// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"

// Sets default values
AGameCharacter::AGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HP = 100.0f;
	AIPerceptionStimuliSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSource"));
	
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//OnHPChanged.AddLambda([](float Input) {  });
}


// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGameCharacter::SaveGame(UGameProgressSave* SaveInstance)
{
	if (!SaveInstance)
		return;

}
void AGameCharacter::LoadGame(UGameProgressSave* LoadInstance)
{
	if (!LoadInstance)
		return;
}

float AGameCharacter::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	//Damage Log
	UE_LOG(LogTemp, Log, TEXT("%s Damaged By %s // Damage Amount : %f"), *GetName(), *DamageCauser->GetName(), DamageAmount);

	//HP 변화 알림
	OnHPChanged.Broadcast(HP);

	return DamageAmount;
}

void AGameCharacter::SetWeapon(AWeaponBase* NewWeapon)
{
	NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, Name_Weapon);
	Weapon = NewWeapon;
}

