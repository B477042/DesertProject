// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GunStateComponent.generated.h"

/*
* 

*/

UENUM(BlueprintType)
enum class FFireMode : uint8
{
	Safty,
	SemiAuto,
	FullAuto,
	Burst
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DESERTPROJECT_API UGunStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGunStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	
	//Before Fire, Check Fire Mode. if Fire mode is Safty return true. else return false
	bool IsSetSafty();
	
	FFireMode GetFireMode() { return FireMode; }



protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "FireMode", meta = (AllowPrivateAccess = true))
		FFireMode FireMode;

};
