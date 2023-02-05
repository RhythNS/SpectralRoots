// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonStatics.h"
#include "FMODBlueprintStatics.h"
#include "GameMode/Tree/TreeGameMode.h"
#include "GameMode/Tree/TreeGameState.h"
#include "GameMode/Tree/TreePlayerState.h"
#include "GameMode/SpectralRootsGameInstance.h"
#include "Player/SpectralRootsCharacter.h"
#include "Player/SpectralRootsHUD.h"
#include "Player/SpectralRootsPlayerController.h"
#include "Sound/OneShotManager.h"
#include "Kismet/GameplayStatics.h"

ATreeGameMode* UCommonStatics::GetGameMode(const UObject* worldContext)
{
    return worldContext->GetWorld()->GetAuthGameMode<ATreeGameMode>();
}

ATreeGameState* UCommonStatics::GetGameState(const UObject* worldContext)
{
	return worldContext->GetWorld()->GetGameState<ATreeGameState>();
}

USpectralRootsGameInstance* UCommonStatics::GetGameInstance(const UObject* worldContext)
{
	return Cast<USpectralRootsGameInstance>(UGameplayStatics::GetGameInstance(worldContext));
}

ASpectralRootsCharacter* UCommonStatics::GetPlayer(const UObject* worldContext)
{
	return Cast<ASpectralRootsCharacter>(UGameplayStatics::GetPlayerPawn(worldContext, 0));
}

ASpectralRootsHUD* UCommonStatics::GetHUD(const UObject* worldContext)
{
	return UGameplayStatics::GetPlayerController(worldContext, 0)->GetHUD<ASpectralRootsHUD>();
}

ASpectralRootsPlayerController* UCommonStatics::GetPlayerController(const UObject* worldContext)
{
	return Cast<ASpectralRootsPlayerController>(UGameplayStatics::GetPlayerController(worldContext, 0));
}

UDictManager* UCommonStatics::GetDictManager(const UObject* worldContext)
{
	/*
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(world, AGlobalsActor::StaticClass(), foundActors);

	if (foundActors.Num() == 0)
		return nullptr;

	return Cast<AGlobalsActor>(foundActors[0])->GetDictManager();
	*/

	return nullptr;
}

void UCommonStatics::HandleOneShoot(UObject* worldContext, FFMODEventInstance toManage)
{
	ASpectralRootsHUD* hud = GetHUD(worldContext->GetWorld());
	if (hud == nullptr)
		return;

	hud->oneShootManager->AddInstance(toManage);
}

void UCommonStatics::HandleAttachedOneShoot(UObject* worldContext, UFMODAudioComponent* toManage)
{
	if (toManage == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Handle Attached One Shoot just got a null to manage!"));
		return;
	}

	FFMODEventInstance inst;
	inst.Instance = toManage->StudioInstance;
	HandleOneShoot(worldContext, inst);
}
