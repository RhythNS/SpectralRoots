// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SpectralRootsHUD.h"

void ASpectralRootsHUD::InvokeFadeCallback(const FFadeFinished& onFinished)
{
	onFinished.ExecuteIfBound();
}
