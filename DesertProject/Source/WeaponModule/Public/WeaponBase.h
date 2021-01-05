// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class WEAPONMODULE_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//Actor which owning this Weapon
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Info", meta = (AllowPrivateAccess = "true", DisplayName = "OwnerActor"))
		TSoftObjectPtr<AActor> OwnerActor;


};
