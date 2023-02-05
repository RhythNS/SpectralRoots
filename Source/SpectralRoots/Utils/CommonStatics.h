// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonStatics.generated.h"

class UDictManager;
class ATreeGameState;
class USpectralRootsGameInstance;
class ATreeGameMode;
class ASpectralRootsCharacter;
class ASpectralRootsPlayerController;
class ASpectralRootsHUD;
struct FFMODEventInstance;
class UFMODAudioComponent;

UCLASS()
class SPECTRALROOTS_API UCommonStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static ATreeGameMode* GetGameMode(const UObject* worldContext);

	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static ATreeGameState* GetGameState(const UObject* worldContext);

	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static USpectralRootsGameInstance* GetGameInstance(const UObject* worldContext);

	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static ASpectralRootsCharacter* GetPlayer(const UObject* worldContext);

	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static ASpectralRootsHUD* GetHUD(const UObject* worldContext);

	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static ASpectralRootsPlayerController* GetPlayerController(const UObject* worldContext);

	UFUNCTION(BlueprintPure, Category = "Statics", meta = (WorldContext = "worldContext"))
	static UDictManager* GetDictManager(const UObject* worldContext);

	UFUNCTION(BlueprintCallable, Category = "InGame", meta = (WorldContext = "worldContext"))
	static void HandleOneShoot(UObject* worldContext, FFMODEventInstance toManage);

	UFUNCTION(BlueprintCallable, Category = "InGame", meta = (WorldContext = "worldContext"))
	static void HandleAttachedOneShoot(UObject* worldContext, UFMODAudioComponent* toManage);
};
