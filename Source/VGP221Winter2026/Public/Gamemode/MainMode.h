// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "Player/FPSCharacter.h"
#include "MainMode.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2026_API AMainMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;

	UFUNCTION()
	void HandlePlayerDied();

	UFUNCTION()
	void GoToGameOver();

protected:
	UPROPERTY()
	int32 AliveEnemyCount;
	
	UFUNCTION()
	void HandleEnemyDied();
	
};
