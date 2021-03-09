// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"

#include "GameProgressSave.h"

#include "GameCharacter.generated.h"


/*
	* Basic Character of this game
	* What Character in the Game have in common
	* Child Class : PlayerCharacter, NPCCharacter
	* Component : 
	
*/



DECLARE_MULTICAST_DELEGATE_OneParam(FOnHPChanged, float);

//UINTERFACE()
//class UTemprateInterface : public UInterface
//{
//	GENERATED_BODY()
//};
//
//class ITemprateInterface
//{
//	GENERATED_BODY()
//};



UCLASS()
class DESERTPROJECT_API AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents()override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual void SaveGame(UGameProgressSave* SaveInstance);
	UFUNCTION()
	virtual void LoadGame(UGameProgressSave* LoadInstance);

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)override;



public:
	FOnHPChanged OnHPChanged;
protected:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
		UAIPerceptionStimuliSourceComponent* AIPerceptionStimuliSource;
	//Default Value : 100.0f
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Stats")
		float HP;

};
