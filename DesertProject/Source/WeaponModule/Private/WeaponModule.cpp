// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponModule.h"
#include "Logging.h"

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FWeaponModule"

void FWeaponModule::StartupModule()
{
}

void FWeaponModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWeaponModule, WeaponModule);