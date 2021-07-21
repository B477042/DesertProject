// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GunAnimInstance.generated.h"

DECLARE_DELEGATE(FParticlePlayDelegate);

UENUM(meta = (ToolTip = "Which Montage you want to play"))
enum class EGunMontageToPlay : uint8
{
	E_Default = 0,
	E_Fire,
	E_Reload,
	E_Melee
	
};


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
	void PlayMontage(EGunMontageToPlay Mode);
	
protected:
	UFUNCTION()
		void AnimNotify_MuzzleFlash();
	UFUNCTION()
		void AnimNotify_EjectBullet();
public:
	FParticlePlayDelegate OnMuzzleFlash;
	FParticlePlayDelegate OnEjectBullet;
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Fire;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Reload;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Melee;
	
};
