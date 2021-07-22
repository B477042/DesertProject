// Fill out your copyright notice in the Description page of Project Settings.


#include "GunAnimInstance.h"

UGunAnimInstance::UGunAnimInstance()
{
	/*
	 *	Set Anim Montages
	 *
	 */
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MON_Fire(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Gun/Gun_Fire_Montage.Gun_Fire_Montage'"));
	if (MON_Fire.Succeeded())
	{
		Montage_Fire = MON_Fire.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>Mon_Reload(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Gun/Gun_Reload_Montage.Gun_Reload_Montage'"));
	if (Mon_Reload.Succeeded())
	{
		Montage_Reload = Mon_Reload.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>Mon_Melee(TEXT("AnimMontage'/Game/MyFolder/Animation/Montage/Gun/Gun_Melee_Attack_Montage.Gun_Melee_Attack_Montage'"));
	if (Mon_Melee.Succeeded())
	{
		Montage_Melee = Mon_Melee.Object;
	}
}

void UGunAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UGunAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UGunAnimInstance::PlayMontage(EGunMontageToPlay Mode)
{
	//If is Any Montage Play. Return
	if(Montage_IsPlaying(nullptr))
	{
		return;
	}
	
	switch(Mode)
	{
	case EGunMontageToPlay::E_Fire:
		Montage_Play(Montage_Fire);
		break;
	case EGunMontageToPlay::E_Reload:
		Montage_Play(Montage_Reload);
		break;
	case EGunMontageToPlay::E_Melee:
		Montage_Play(Montage_Melee);
		break;
	default:
		break;
	}
}

void UGunAnimInstance::AnimNotify_MuzzleFlash()
{
	OnMuzzleFlash.Execute();
}

void UGunAnimInstance::AnimNotify_EjectBullet()
{
	OnEjectBullet.Execute();
}
