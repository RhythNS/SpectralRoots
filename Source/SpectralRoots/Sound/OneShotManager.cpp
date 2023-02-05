// Fill out your copyright notice in the Description page of Project Settings.

#include "OneShotManager.h"
#include "Utils/CommonStatics.h"
#include "Player/SpectralRootsHUD.h"

// Sets default values
AOneShotManager::AOneShotManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOneShotManager::BeginPlay()
{
	Super::BeginPlay();

	UCommonStatics::GetHUD(GetWorld())->oneShootManager = this;
}

void AOneShotManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for (int32 i = 0; i < instances.Num(); i++)
	{
		if (instances[i].Instance && instances[i].Instance->isValid())
		{
			instances[i].Instance->stop(FMOD_STUDIO_STOP_MODE::FMOD_STUDIO_STOP_ALLOWFADEOUT);
			instances[i].Instance->release();
		}
	}
}

inline bool AOneShotManager::IsValid(FFMODEventInstance& instance)
{
	if (instance.Instance == nullptr || instance.Instance->isValid() == false)
		return false;

	FMOD_STUDIO_PLAYBACK_STATE playbackState;
	FMOD_RESULT result = instance.Instance->getPlaybackState(&playbackState);
	if (result != FMOD_RESULT::FMOD_OK)
		return false;

	if (playbackState == FMOD_STUDIO_PLAYBACK_STATE::FMOD_STUDIO_PLAYBACK_STOPPING
		|| playbackState == FMOD_STUDIO_PLAYBACK_STATE::FMOD_STUDIO_PLAYBACK_STOPPED)
		return false;

	return true;
}

void AOneShotManager::RemoveUnused()
{
	for (int32 i = instances.Num() - 1; i >= 0; i--)
	{
		if (IsValid(instances[i]) == false)
		{
			if (instances[i].Instance && instances[i].Instance->isValid())
				instances[i].Instance->release();

			instances.RemoveAt(i);
		}
	}
}

// Called every frame
void AOneShotManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RemoveUnused();

	if (instances.Num() == 0)
		SetActorTickEnabled(false);
}

void AOneShotManager::AddInstance(FFMODEventInstance oneShoot)
{
	if (IsValid(oneShoot) == false)
		return;

	instances.Add(oneShoot);
	SetActorTickEnabled(true);
}

void AOneShotManager::OnPause()
{
	RemoveUnused();

	for (int32 i = 0; i < instances.Num(); i++)
		instances[i].Instance->setPaused(true);
}

void AOneShotManager::OnResume()
{
	for (int32 i = 0; i < instances.Num(); i++)
		instances[i].Instance->setPaused(false);
}

