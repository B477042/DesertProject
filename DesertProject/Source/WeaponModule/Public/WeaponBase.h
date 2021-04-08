// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
//#include ""
#include "WeaponBase.generated.h"

UCLASS()
class WEAPONMODULE_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PickedBy(AActor* OtherActor);

	void DropWeapon();



	


	/*virtual void SaveGame(class UGameProgressSave* SaveInstance);
	virtual void LoadGame(class UGameProgressSave* LoadInstance);*/



protected:
	//Actor which owning this Weapon
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Info", meta = (AllowPrivateAccess = "true", DisplayName = "Owner Actor"))
		TSoftObjectPtr<AActor> OwnerActor;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh", meta = (AllowPrivateAccess = "true", DisplayName = "Mesh Component"))
		UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh", meta = (AllowPrivateAccess = "true", DisplayName = "Box Trigger"))
		UBoxComponent* BoxTrigger;




	
};
