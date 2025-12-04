// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	if (!PawnSensing)
	{
		PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
		PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);
	}
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(StartingBehaviorTree);

	UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
	BlackboardComp->SetValueAsFloat("BBDamageAmount", 50.0f);
}

void AEnemyAIController::OnSeePawn(APawn* PlayerPawn)
{
	AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(PlayerPawn);
	if (!PlayerCharacter) return;
	
	OnCanSeePlayer(true, PlayerPawn);

	RunRetriggerableTimer();
}

void AEnemyAIController::OnCanSeePlayer(bool SeePlayer, UObject* PlayerObject)
{
	UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
	BlackboardComp->SetValueAsBool("CanSeePlayer", SeePlayer);

	if (SeePlayer)
	{
		BlackboardComp->SetValueAsObject("PlayerTarget", PlayerObject);
	}
}

void AEnemyAIController::RunRetriggerableTimer()
{
	GetWorldTimerManager().ClearTimer(RetriggerableTimeHandle);
	FunctionDelegate.BindUFunction(this, FName("OnCanSeePlayer"), false, nullptr);
	GetWorldTimerManager().SetTimer(RetriggerableTimeHandle, FunctionDelegate, PawnSensing->SensingInterval * 2.0f, false);

}
