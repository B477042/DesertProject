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
class WEAPONMODULE_API AGunsBase : public AWeaponBase
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
	//Attachments of this Weapon
	/*UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Attachment", meta = (AllowPrivateAccess = true))
		TArray<TWeakObjectPtr<AActor>> Attahments;*/

	//Maximum number of attachments
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Attachment", meta = (AllowPrivateAccess = true))
		uint8  n_attachemts;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Info", meta = (AllowPrivateAccess = true))
		class UGunStateComponent* GunStateComponent;

		

	
};
