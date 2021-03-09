// Fill out your copyright notice in the Description page of Project Settings.


#include "DesertGameInstance.h"
#include "..\Public\DesertGameInstance.h"
#include "GameCharacter.h"

UDesertGameInstance::UDesertGameInstance()
{

}

bool UDesertGameInstance::AddCharacter(AGameCharacter * NewCharacter)
{
	if (!NewCharacter)return false;

	const bool bIsContain = M_Characters.Contains(NewCharacter);
	if (bIsContain)return false;

	M_Characters.Add(NewCharacter);


	return true;
}

bool UDesertGameInstance::ClearManager()
{
	return false;
}
