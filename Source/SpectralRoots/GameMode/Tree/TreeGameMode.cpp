// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeGameMode.h"
#include "Player\SpectralRootsCharacter.h"
#include "Components\CapsuleComponent.h"
#include "Env\CheckpointStart.h"

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
