// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacterAnimInstance.h"

UFPSCharacterAnimInstance::UFPSCharacterAnimInstance()
{

	/*
	 * Load Anim Montage
	 */
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MONTAGE_Fire(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Arm/Arms_Fire_Montage.Arms_Fire_Montage'"));
	if(MONTAGE_Fire.Succeeded())
	{
		Montage_Fire = MONTAGE_Fire.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MONTAGE_ADSFire(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Arm/Arms_Aim_Fire_Montage.Arms_Aim_Fire_Montage'"));
	if(MONTAGE_ADSFire.Succeeded())
	{
		Montage_ADSFire = MONTAGE_ADSFire.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MONTAGE_Reload(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Arm/Arms_Reload_Montage.Arms_Reload_Montage'"));
	if(MONTAGE_Reload.Succeeded())
	{
		Montage_Reload = MONTAGE_Reload.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MONTAGE_Melee(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Arm/Arms_Melee_Attack_Montage.Arms_Melee_Attack_Montage'"));
	if(MONTAGE_Melee.Succeeded())
	{
		Montage_Melee = MONTAGE_Melee.Object;
	}
	
}

void UFPSCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UFPSCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
