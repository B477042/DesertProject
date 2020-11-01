// Fill out your copyright notice in the Description page of Project Settings.


#include "DesertGameMode.h"
#include "DesertGameState.h"
#include "DesertPlayerState.h"
#include "DesertGameInstance.h"

ADesertGameMode::ADesertGameMode()
{
	PlayerStateClass = ADesertPlayerState::StaticClass();
	GameStateClass = ADesertGameState::StaticClass();
	
	
}