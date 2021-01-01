// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MySkySphere.generated.h"

UCLASS()
class DESERTPROJECT_API AMySkySphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySkySphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SunLight")
	TWeakObjectPtr<class ADirectionalLight> SunLight;
	UPROPERTY(VisibleAnywhere, Category = "SunLight")
	float tempTimer;

};
