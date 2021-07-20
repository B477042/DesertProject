// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

//#include ""
#include "WeaponBase.generated.h"


/*
 *	Don't Use Capsule Component. Instead of that use Mesh's Collision
 * 
 */
UCLASS()
class DESERTPROJECT_API AWeaponBase : public ACharacter
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

	 


protected:
	//Actor which owning this Weapon
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Info", meta = (AllowPrivateAccess = "true", DisplayName = "Owner Actor"))
		TSoftObjectPtr<ACharacter> OwnerCharactor;
	
		 
	
};
