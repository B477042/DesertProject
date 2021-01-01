// Fill out your copyright notice in the Description page of Project Settings.


#include "DesertGameMode.h"
#include "DesertGameState.h"
#include "DesertPlayerState.h"
#include "DesertGameInstance.h"
#include "PlayerCharacter.h"
#include "FPSPlayerController.h"

ADesertGameMode::ADesertGameMode()
{
	PlayerStateClass = ADesertPlayerState::StaticClass();
	GameStateClass = ADesertGameState::StaticClass();
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = AFPSPlayerController::StaticClass();
	
}