// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GunAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONMODULE_API UGunAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UGunAnimInstance();
protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:




protected:

};
