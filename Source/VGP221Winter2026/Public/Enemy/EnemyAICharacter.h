// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAICharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemyDied);

UCLASS()
class VGP221WINTER2026_API AEnemyAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAICharacter();

	UPROPERTY()
	FOnEnemyDied OnEnemyDied;

	UFUNCTION()
	void OnDamage(float damage);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float DamageAmount = 10.0f;

private:
	int Health = 100.0f;
};
