// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "GunStateComponent.h"
#include "GunsBase.generated.h"

/**
 * 
 */




UCLASS()
class DESERTPROJECT_API AGunsBase : public AWeaponBase
{
	GENERATED_BODY()
public:
	AGunsBase();
protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Fire();
	class UGunStateComponent* GetGunStateComponent()const { return  GunStateComponent; }


protected:
	//Skeletal Socket Names
	const FName Name_Muzzle = "Muzzle";
	const FName Name_ScopeSocket = "ScopeSocket";
	const FName Name_BulletEject = "ShellEjectionSocket";

	//Maximum number of attachments
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Attachment", meta = (AllowPrivateAccess = true))
		uint8  Max_Attachemts;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Info", meta = (AllowPrivateAccess = true))
		UGunStateComponent* GunStateComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Fire;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Reload;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Montage", meta = (AllowPrivateAccess = true))
		UAnimMontage* Montage_Melee;

	//Muzzle Flash
	UPROPERTY(VisibleInstanceOnly, Category = "Particle System")
		UParticleSystemComponent* PS_Muzzle;
	//Bullet Ejcet Effect
	UPROPERTY(VisibleInstanceOnly, Category = "Particle System")
		UParticleSystemComponent* PS_Eject;
};
