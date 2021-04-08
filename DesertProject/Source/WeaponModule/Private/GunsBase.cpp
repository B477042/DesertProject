// Fill out your copyright notice in the Description page of Project Settings.


#include "GunsBase.h"

AGunsBase::AGunsBase()
{
	GunStateComponent = CreateDefaultSubobject<UGunStateComponent>(TEXT("GUNSTATECOMPNENT"));
	
}


void AGunsBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGunsBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

void AGunsBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGunsBase::Fire()
{
	//If SaftyMode return
	if (GunStateComponent->IsSetSafty())return;



}