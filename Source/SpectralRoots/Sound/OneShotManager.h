// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/Pausable.h"
#include "FMODBlueprintStatics.h"
#include "OneShotManager.generated.h"

UCLASS()
class SPECTRALROOTS_API AOneShotManager : public AActor, public IPausable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOneShotManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddInstance(FFMODEventInstance oneShoot);
	
	virtual void OnPause_Implementation();

	virtual void OnResume_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	inline bool IsValid(FFMODEventInstance& instance);

	void RemoveUnused();

	TArray<FFMODEventInstance> instances;
};
