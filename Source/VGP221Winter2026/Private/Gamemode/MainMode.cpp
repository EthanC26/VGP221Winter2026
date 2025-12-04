// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/MainMode.h"


void AMainMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	//1. to pPRint Screen
	//display a debug message for five seconds
	//the -1 "key" value means it will only appear once
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Welcome to VGP221!"));

	//2. to Print console
	UE_LOG(LogTemp, Warning, TEXT("TEEHEE"));

	//3. printing values to console
	int TestValue = 40;
	float TestFloat = 3.14159f;
	UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i, TestFlaot: %f"), TestValue, TestFloat);

	//4. modern way of debugging values
	UE_LOGFMT(LogTemp, Warning, "TestNumber: {0}, TestFlaot: {1} CoolGuy: {2}", TestValue, TestFloat, "Erhan");

	//find all enemies in the level
	TArray<AActor*> Enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAICharacter::StaticClass(), Enemies);

	AliveEnemyCount = Enemies.Num();
	UE_LOG(LogTemp, Warning, TEXT("Enemy Count: %d"), AliveEnemyCount);

	// bind to each enemy's OnEnemyDied event
	for (AActor* EnemyActor : Enemies)
	{
		AEnemyAICharacter* EnemyCharacter = Cast<AEnemyAICharacter>(EnemyActor);
		if (EnemyCharacter)
		{
			EnemyCharacter->OnEnemyDied.AddDynamic(this, &AMainMode::HandleEnemyDied);
		}
	}

	// Get player and bind on died
	AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player) {

		player->OnPlayerDied.AddDynamic(this, &AMainMode::HandlePlayerDied);

	}
	
}

void AMainMode::HandlePlayerDied()
{
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMainMode::GoToGameOver, 2.0f, false);
}

void AMainMode::GoToGameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Player Died! Game Over!"));

	UGameplayStatics::SetGamePaused(GetWorld(), true);

	// Create and display the GameOverWidget
	   // Get player controller
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!PC) return;

	// Get HUD and call ShowGameOverMenu
	if (AGameHud* GameHud = Cast<AGameHud>(PC->GetHUD()))
	{
		int32 FinalScore = 0; // Replace with actual score if you track it
		GameHud->ShowGameOverMenu(FinalScore);
	}
}

void AMainMode::HandleEnemyDied()
{
	AliveEnemyCount--;
	UE_LOG(LogTemp, Warning, TEXT("Enemy Died! Remaining Enemies: %d"), AliveEnemyCount);
	if (AliveEnemyCount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("All Enemies Defeated! You Win!"));
		GoToGameOver();
	}
}
