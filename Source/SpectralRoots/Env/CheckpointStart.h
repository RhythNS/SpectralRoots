// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "CheckpointStart.generated.h"

UCLASS()
class SPECTRALROOTS_API ACheckpointStart : public APlayerStart
{
	GENERATED_BODY()
	
public:
	ACheckpointStart(const FObjectInitializer& ObjectInitializer);
};
