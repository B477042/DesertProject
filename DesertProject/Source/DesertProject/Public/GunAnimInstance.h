// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GunAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DESERTPROJECT_API UGunAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UGunAnimInstance();
protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:

	
protected:
	UFUNCTION()
		void AnimNotify_MuzzleFlash();
public:

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Fire;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Reload;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Melee;
	
};
