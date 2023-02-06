// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TreeGameMode.generated.h"

class ASpectralRootsCharacter;
class ACheckpointStart;

UCLASS()
class SPECTRALROOTS_API ATreeGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void TeleportToCheckpoint(ASpectralRootsCharacter* toTeleport);

	UFUNCTION(BlueprintCallable)
	void UnlockCheckpoint(ACheckpointStart* checkpoint);

	UFUNCTION(BlueprintCallable)
	void SetActiveCheckpoint(ACheckpointStart* checkpoint);

protected:
	UPROPERTY(VisibleAnywhere)
	TArray<ACheckpointStart*> discorvedCheckpoints;

	UPROPERTY(VisibleAnywhere)
	ACheckpointStart* activeCheckpoint = nullptr;
};
