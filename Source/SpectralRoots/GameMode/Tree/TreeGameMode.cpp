// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeGameMode.h"
#include "Player\SpectralRootsCharacter.h"
#include "Components\CapsuleComponent.h"
#include "Env\CheckpointStart.h"
#include "Interface\Pausable.h"
#include "Kismet/GameplayStatics.h"

void ATreeGameMode::RegisterPausable(UObject* pausable)
{
	if (pausables.Contains(pausable))
	{
		UE_LOG(LogTemp, Log, TEXT("Pausable tried to add itself twice!"));
		return;
	}
	pausables.Add(pausable);
}

void ATreeGameMode::UnRegisterPausable(UObject* pausable)
{
	if (!pausables.Contains(pausable))
	{
		UE_LOG(LogTemp, Log, TEXT("Pausable was not found. Could not be removed!"));
		return;
	}
	pausables.Remove(pausable);
}

void ATreeGameMode::Pause()
{
	if (UGameplayStatics::IsGamePaused(this))
		return;

	for (UObject* pausable : pausables)
		IPausable::Execute_OnPause(pausable);

	UGameplayStatics::SetGamePaused(this, true);
}

void ATreeGameMode::UnPause()
{
	if (!UGameplayStatics::IsGamePaused(this))
		return;

	for (UObject* pausable : pausables)
		IPausable::Execute_OnResume(pausable);

	UGameplayStatics::SetGamePaused(this, false);
}

void ATreeGameMode::TeleportToCheckpoint(ASpectralRootsCharacter* toTeleport)
{
	UCapsuleComponent* capsule = activeCheckpoint->GetCapsuleComponent();

	toTeleport->TeleportTo(capsule->GetComponentLocation(), capsule->GetComponentRotation());
}

void ATreeGameMode::UnlockCheckpoint(ACheckpointStart* checkpoint)
{
	if (!discorvedCheckpoints.Contains(checkpoint))
		discorvedCheckpoints.Add(checkpoint);
}

void ATreeGameMode::SetActiveCheckpoint(ACheckpointStart* checkpoint)
{
	if (!checkpoint)
	{
		UE_LOG(LogTemp, Log, TEXT("Gotten null checkpoint when setting for the active checkpoint!"));
		return;
	}

	UnlockCheckpoint(checkpoint);
	activeCheckpoint = checkpoint;
}
