// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameCharacter.h"
#include "BasicCharacterAnimInstance.generated.h"

/**
 * Basic AnimInstance for this game.
 * Prevent code from increasing by unnecessary inheritance
 * Minimize coding from blueprints
 */
UCLASS()
class DESERTPROJECT_API UBasicCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UBasicCharacterAnimInstance();

protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:

	void SetCrouch(bool bSet) {bIsCrouch = bSet;}
	void SetIronsights(bool bSet){ bOnIronsights = bSet; }
	void SetAttacking(bool bSet){ bIsAttacking = bSet; }
	void SetAccelerating(bool bSet){ bIsAccelerating = bSet; }

protected:
	//
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		uint8 bIsInAir;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		uint8 bIsAccelerating;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		uint8 bIsFullBody;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		uint8 bIsAttacking;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		uint8 bIsCrouch;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		uint8 bOnIronsights;



	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		float Speed;
	/*UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
	float bs_Speed;*/
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		float Direction;


	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		AGameCharacter* Character;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		float Pitch;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		float  Roll;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		float Yaw;
	UPROPERTY(BlueprintReadOnly, Category = "variable", meta = (AllowPrivateAccess = "true"))
		float YawDelta;
	FRotator RotationLastTick;
	FVector PrevPos;


};
