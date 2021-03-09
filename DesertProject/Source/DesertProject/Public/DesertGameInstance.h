// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DesertGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DESERTPROJECT_API UDesertGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UDesertGameInstance();
	const TArray<TWeakObjectPtr< class AGameCharacter>> GetCharacterManager() { return M_Characters;}

	 bool AddCharacter(class AGameCharacter* NewCharacter);
	 bool ClearManager();

protected:
	
	


protected:
	//Manager of Characters
	TArray<TWeakObjectPtr< class AGameCharacter>> M_Characters;


};
