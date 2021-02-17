// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"


AProjectileBase::AProjectileBase()
{
	MovementComponent = CreateDefaultSubobject<UMyProjectileMovementComponent>(TEXT("MovementComponent"));
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent=RootScene;


}






// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

