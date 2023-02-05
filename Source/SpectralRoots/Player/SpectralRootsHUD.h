// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SpectralRootsHUD.generated.h"

class AOneShotManager;

UCLASS()
class SPECTRALROOTS_API ASpectralRootsHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AOneShotManager* oneShootManager = nullptr;
};
