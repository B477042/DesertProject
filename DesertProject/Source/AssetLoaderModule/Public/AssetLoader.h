// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/StreamableManager.h"
#include "AssetLoader.generated.h"


/**
 * Class for Asynchronous Load
 */
UCLASS(config=AssetLoader)
class ASSETLOADERMODULE_API UAssetLoader : public UObject
{
	GENERATED_BODY()

public:

	UAssetLoader();

	UPROPERTY(config)
		TArray<FSoftObjectPath> WeaponAssets;
};
