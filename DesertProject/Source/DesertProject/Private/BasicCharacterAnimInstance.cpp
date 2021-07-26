// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacterAnimInstance.h"
#include "Kismet/KismetMathLibrary.h"


UBasicCharacterAnimInstance::UBasicCharacterAnimInstance()
{
	bIsInAir = false;
	bIsAccelerating = false;
	bIsFullBody = false;
	bIsAttacking = false;
	bIsCrouch = false;
	bOnADS = false;
	Speed = 0.f;
	Direction = 0.0f;

	Pitch = 0.0f, Roll = 0.0f, Yaw = 0.0f;
	//AimPitch = 0.0f, AimYaw = 0.0f;
	YawDelta = 0.0f;
	PrevPos = FVector::ZeroVector;
	RotationLastTick = FRotator::ZeroRotator;
}



void UBasicCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	Character = Cast<AGameCharacter>(TryGetPawnOwner());
	if (!Character)
		UE_LOG(LogTemp, Error, TEXT("Owner Casting Failed!!"));
}

void UBasicCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!Character)return;

	//update is in air
	bIsInAir = Character->GetMovementComponent()->IsFalling();

	//update speed
	Speed = Character->GetVelocity().Size();

	////update is accelerating
	//float accelerate = Character->GetCharacterMovement()->GetCurrentAcceleration().Size();
	//accelerate > 0 ? bIsAccelerating = true : bIsAccelerating = false;

	//update is fullbody
	GetCurveValue(TEXT("FullBody")) > 0 ? bIsFullBody = true : bIsFullBody = false;


	//Update pitch,yaw,roll
	RotationLastTick = Character->GetActorRotation();

	FRotator deltaRot = UKismetMathLibrary::NormalizedDeltaRotator(Character->GetBaseAimRotation(), Character->GetActorRotation());
	Pitch = deltaRot.Pitch;
	Yaw = deltaRot.Yaw;
	Roll = deltaRot.Roll;

	YawDelta = UKismetMathLibrary::FInterpTo(YawDelta,
		UKismetMathLibrary::NormalizedDeltaRotator(RotationLastTick, Character->GetActorRotation()).Roll / DeltaSeconds / 10.0f,
		DeltaSeconds, 6.0f
	);

	////Update bs_Walk Speed
	Direction = CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());
}

