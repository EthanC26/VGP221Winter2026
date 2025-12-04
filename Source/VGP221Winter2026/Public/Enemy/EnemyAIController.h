// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "Player/FPSCharacter.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2026_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AEnemyAIController();

protected:
	//Called when the game starts or when spawned
    virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* StartingBehaviorTree;

	UPROPERTY(EditAnywhere)
	UPawnSensingComponent* PawnSensing;

	UFUNCTION()
	void OnSeePawn(APawn* PlayerPawn);

	UFUNCTION()
	void OnCanSeePlayer(bool SeePlayer, UObject* PlayerObject);

	FTimerHandle RetriggerableTimeHandle;
	FTimerDelegate FunctionDelegate;
	void RunRetriggerableTimer();

};
