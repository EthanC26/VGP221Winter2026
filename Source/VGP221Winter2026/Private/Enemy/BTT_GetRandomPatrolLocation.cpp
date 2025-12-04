// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTT_GetRandomPatrolLocation.h"

EBTNodeResult::Type UBTT_GetRandomPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (NavSystem)
	{
		NavSystem->K2_GetRandomLocationInNavigableRadius(GetWorld(), OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(), RandomLocation, 2000.0f);
	}
	else
	{
	  return EBTNodeResult::Failed;
    }

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("RandomPatrolLocation"), RandomLocation);

	return EBTNodeResult::Succeeded;
}
