// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
//#include ""

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESHCOMPONENT"));
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BOXTRIGGER"));


	BoxTrigger->SetCollisionProfileName("NoCollision");

	
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
	OwnerActor = OtherActor;

	BoxTrigger->SetCollisionProfileName("NoCollision");
}

void AWeaponBase::DropWeapon()
{
	OwnerActor.Reset();
}

//void AWeaponBase::SaveGame(UGameProgressSave * SaveInstance)
//{
//	if (!SaveInstance)return;
//}
//
//void AWeaponBase::LoadGame(UGameProgressSave * LoadInstance)
//{
//	if (!LoadInstance)return;
//}
//
