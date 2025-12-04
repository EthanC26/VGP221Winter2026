// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Projectile/FPSProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/GameHud.h"
#include "FPSCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);

UCLASS()
class VGP221WINTER2026_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	UPROPERTY()
	USkeletalMeshComponent* FPSMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector MuzzleOffset;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AFPSProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)
	FOnPlayerDied OnPlayerDied;

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void EndJump();

	UFUNCTION()
	void Fire();

	UFUNCTION()
	void OnHurtPlayer(float DamageAmount);

	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	float Health = 100.0f;
	float MaxHealth = 100.0f;

};
