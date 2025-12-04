// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTT_Attack.h"

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	AAIController* AICon = OwnerComp.GetAIOwner();

	//Method 1: Build in damage System
	 AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	 UGameplayStatics::ApplyDamage(player, 1.0f, AICon, AICon->GetPawn(), UDamageType::StaticClass());

	//Method 2: Calling damage 
	// AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// player->OnHurtPlayer(5.0f);

	//Method 3: Using pawn
	//AEnemyAICharacter* enemyCharacter = Cast<AEnemyAICharacter>(AICon->GetPawn());
	//AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//player->OnHurtPlayer(enemyCharacter->DamageAmount);

	//Method 4: Using BalckBoard
	// float BBDamageAmount = OwnerComp.GetBlackboardComponent()->GetValueAsFloat("BBDamageAmount");
	// AFPSCharacter* player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// player->OnHurtPlayer(BBDamageAmount);


	return EBTNodeResult::Succeeded;
}

