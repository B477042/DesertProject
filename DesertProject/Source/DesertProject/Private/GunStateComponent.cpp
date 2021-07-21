// Fill out your copyright notice in the Description page of Project Settings.


#include "GunStateComponent.h"

// Sets default values for this component's properties
UGunStateComponent::UGunStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	
	// ...
}


// Called when the game starts
void UGunStateComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



bool UGunStateComponent::IsCountEmpty()
{
	return AmmoCount <= 0 ? true : false;
}

void UGunStateComponent::ToggleFireMode()
{
	
}


