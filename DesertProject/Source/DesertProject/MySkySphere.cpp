// Fill out your copyright notice in the Description page of Project Settings.


#include "MySkySphere.h"
#include "Engine/DirectionalLight.h"

// Sets default values
AMySkySphere::AMySkySphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tempTimer = 0.f;
}

// Called when the game starts or when spawned
void AMySkySphere::BeginPlay()
{
	Super::BeginPlay();

	if(SunLight.IsValid())
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test Message"));
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Test Message"));
	
	
}

// Called every frame
void AMySkySphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SunLight.IsValid())
	{
		tempTimer += DeltaTime;
		
		if (tempTimer >= 0.1f)
		{
			FRotator rotSun = SunLight->GetActorRotation();
		
			SunLight->SetActorRotation(rotSun+FRotator(0.0f,0.50f,0.0f));
	
			tempTimer = 0.0f;
		}
		
	}

}

