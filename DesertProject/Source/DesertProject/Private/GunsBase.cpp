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
	
	
	/*=====================================================================================================
	 * Attach Particle System
	 */
	PS_Eject->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,Name_BulletEject);
	PS_Muzzle->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,Name_Muzzle);
	/*PS_Eject->SetRelativeLocation(FVector(0, 12.0f, 7.0f));
	PS_Muzzle->SetRelativeLocation(FVector(0, 53, 7));*/
	
}


void AGunsBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGunsBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Anim = Cast<UGunAnimInstance>(GetMesh()->GetAnimInstance());
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