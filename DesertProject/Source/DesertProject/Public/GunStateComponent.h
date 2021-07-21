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
	
	SemiAuto=0,
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
	

	
	FFireMode GetFireMode() { return FireMode; }

	bool IsCountEmpty();
	void ToggleFireMode();
protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "FireMode", meta = (AllowPrivateAccess = true))
		FFireMode FireMode=FFireMode::FullAuto;
	//Display Current Ammo Count
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Ammo", meta = (AllowPrivateAccess = true, ToolTip = "Display Current Ammo Count", UIMax = 100.00, UIMin = 0.00))
		uint8 AmmoCount=30;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Ammo", meta = (AllowPrivateAccess = true, UIMax = 100.00, UIMin = 0.00))
		uint8 MaximumAmmo=30;
};
