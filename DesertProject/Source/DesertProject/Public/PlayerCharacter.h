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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents()override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	


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

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, Category = "Attack")
	uint8 bAutoFireMode;



};
