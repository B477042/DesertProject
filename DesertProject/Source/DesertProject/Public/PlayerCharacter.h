// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"
#include "GameFramework/Character.h"

#include "PlayerCharacter.generated.h"


/*
	* A Character which player will controll
	* Receive Key & Mouse Input
	* Components List : 
*/

UCLASS()
class DESERTPROJECT_API APlayerCharacter : public AGameCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	//Socket Name that weapon had being attached to 
	const FName Name_GripPoint = "GripPoint";
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents()override;
	UFUNCTION()
	 void OnCapsuleCompBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void PickUpWeapon(  AActor* Weapon);

protected:
	void initComponents();
	void loadAsset();
	void MoveForward(float NewAxisValue);
	void MoveLeft(float NewAxisValue);
	void LookHorizontal(float NewAxisValue);
	void LookVertical(float NewAxisValue);
	//Shoot the gun or Melee Attack
	void PullTrigger();
	void ReleaseTrigger();
	void AimDownSight();
	void Jump();

	void AttachWeapon( class AWeaponBase* NewWeapon);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera", meta = (AllowPrivateAccess = true))
		UCameraComponent* MainCamera;
	/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MainCamera", meta = (AllowPrivateAccess = true))
		USpringArmComponent* MainSpringArm;*/
	UPROPERTY(VisibleAnywhere, Category = "Attack")
	uint8 bAutoFireMode;



};
