// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "BasicCharacterAnimInstance.h"
#include "FPSCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DESERTPROJECT_API UFPSCharacterAnimInstance : public UBasicCharacterAnimInstance
{
	GENERATED_BODY()
public:
	UFPSCharacterAnimInstance();
protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Montage")
		UAnimMontage* Montage_Fire;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Montage")
		UAnimMontage* Montage_ADSFire;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Montage")
		UAnimMontage* Montage_Reload;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Montage")
		UAnimMontage* Montage_Melee;
};
