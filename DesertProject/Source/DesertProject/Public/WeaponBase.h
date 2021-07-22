// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"


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
	UFUNCTION()
		void OnCharacterOverlapped(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

		



	
	TSoftObjectPtr<ACharacter> OwnerCharactor;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision", meta = (AllowPrivateAccess = true))
	class UBoxComponent* PickUpTrigger;
	
};
