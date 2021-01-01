// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetLoaderModule.h"
#include "Logging.h"

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FAssetLoaderModule"

void FAssetLoaderModule::StartupModule()
{
}

void FAssetLoaderModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAssetLoaderModule, AssetLoaderModule);