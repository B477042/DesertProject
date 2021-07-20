// Fill out your copyright notice in the Description page of Project Settings.


#include "GunsBase.h"
#include "Engine/AssetManager.h"
#include "GunAnimInstance.h"
#include "particles/ParticleSystemComponent.h"

AGunsBase::AGunsBase()
{
	GunStateComponent = CreateDefaultSubobject<UGunStateComponent>(TEXT("GUNSTATECOMPNENT"));
	PS_Muzzle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PSMUZZLE"));
	PS_Eject = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PSEJCT"));
	

	
	/*============================================================================================
	 *	Load Assets
	 *	
	 * Temp Skeletal Mesh Setting
	 *
	 */
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SK_Mesh(TEXT("SkeletalMesh'/Game/M4A4_Animated/Gun/Gun.Gun'"));
	if (SK_Mesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_Mesh.Object);
		GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
	}

	/*
	 * Set Anim Instance
	 */
	static ConstructorHelpers::FClassFinder<UGunAnimInstance>ANIM_GUN(TEXT("AnimBlueprint'/Game/M4A4_Animated/Gun/Gun_AnimBP.Gun_AnimBP_C'"));
	if (ANIM_GUN.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIM_GUN.Class);
	}
	/*
	 *	Set Anim Montages
	 * 
	 */
	static ConstructorHelpers::FObjectFinder<UAnimMontage>MON_Fire(TEXT("AnimMontage'/Game/M4A4_Animated/Gun/Gun_Animations/Gun_Fire_Montage.Gun_Fire_Montage'"));
	if (MON_Fire.Succeeded())
	{
		Montage_Fire = MON_Fire.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>Mon_Reload(TEXT("AnimMontage'/Game/M4A4_Animated/Gun/Gun_Animations/Gun_Reload_Montage.Gun_Reload_Montage'"));
	if (Mon_Reload.Succeeded())
	{
		Montage_Reload = Mon_Reload.Object;
	}
	static ConstructorHelpers::FObjectFinder<UAnimMontage>Mon_Melee(TEXT("AnimMontage'/Game/M4A4_Animated/Gun/Gun_Animations/Gun_Melee_Attack_Montage.Gun_Melee_Attack_Montage'"));
	if (Mon_Melee.Succeeded())
	{
		Montage_Melee = Mon_Melee.Object;
	}
	
	/*=====================================================================================================
	 * Attach Particle System
	 */
	PS_Eject->AttachTo(GetMesh());
	PS_Muzzle->AttachTo(GetMesh());
	PS_Eject->SetRelativeLocation(FVector(0, 12.0f, 7.0f));
	PS_Muzzle->SetRelativeLocation(FVector(0, 53, 7));
	
}


void AGunsBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGunsBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

void AGunsBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGunsBase::Fire()
{
	//If SaftyMode return
	if (GunStateComponent->IsSetSafty())return;


}