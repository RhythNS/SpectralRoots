// Fill out your copyright notice in the Description page of Project Settings.


#include "Env/CheckpointStart.h"

ACheckpointStart::ACheckpointStart(const FObjectInitializer& ObjectInitializer) : APlayerStart(ObjectInitializer)
{
	PlayerStartTag = "Checkpoint";
}
