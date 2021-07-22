// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
//#include ""

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PickUpTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("PickUpTirgger"));

	GetCapsuleComponent()->SetCapsuleRadius(1.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(1.0f);


	PickUpTrigger->SetupAttachment(GetMesh());
	PickUpTrigger->SetRelativeLocation(FVector(0, 12, 0));
	PickUpTrigger->SetBoxExtent(FVector(32.0f, 48.6f, 26.8f));
	PickUpTrigger->SetCollisionProfileName(TEXT("PickUpAble"));
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}
void AWeaponBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PickUpTrigger->OnComponentBeginOverlap.AddDynamic(this,&AWeaponBase::OnCharacterOverlapped);
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

void AWeaponBase::OnCharacterOverlapped(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	

	if (OtherActor->Tags.Find("Player")==INDEX_NONE)
	{
		UE_LOG(LogTemp, Log, TEXT("Not Player"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Hi player"));
	
	
	
}

