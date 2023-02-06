// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SpectralRootsHUD.generated.h"

class AOneShotManager;

DECLARE_DYNAMIC_DELEGATE(FFadeFinished);

UENUM(BlueprintType)
enum FadeBehaviour
{
	FadeInOut,
	FadeIn,
	FadeOut
};

UCLASS()
class SPECTRALROOTS_API ASpectralRootsHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void FadeTo(const FFadeFinished& onFinished, FadeBehaviour behaviour = FadeInOut);
	
	UFUNCTION(BlueprintCallable)
	void InvokeFadeCallback(const FFadeFinished& onFinished);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AOneShotManager* oneShootManager = nullptr;
};
