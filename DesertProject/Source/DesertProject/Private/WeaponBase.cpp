// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/CapsuleComponent.h"
//#include ""

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

	GetCapsuleComponent()->SetCapsuleRadius(1.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(1.0f);
	
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}
void AWeaponBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();


}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::PickedBy(AActor * OtherActor)
{
	OwnerCharactor = OtherActor;

	GetCapsuleComponent()->SetCollisionProfileName("NoCollision");
}

void AWeaponBase::DropWeapon()
{
	OwnerCharactor.Reset();
}

