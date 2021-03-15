// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_PlayerHUD.generated.h"

/**
 * UI that players will see in-game situations
 */
UCLASS()
class DESERTPROJECT_API UWidget_PlayerHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	

	

protected:
	virtual void NativePreConstruct()override;
	virtual void NativeConstruct()override;


protected:


};
