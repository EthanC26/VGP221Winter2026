// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Blueprint/UserWidget.h"
#include "GUI/GameOverButtonWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2026_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void SetUpFinalScore(int32 FinalScore);

protected:
	UPROPERTY(meta = (BindWidget))
	 UTextBlock* FinalScoreText;

	 UPROPERTY(meta = (BindWidget))
	 UVerticalBox* ButtonContanier;

	 UPROPERTY(EditAnywhere)
	 TSubclassOf<UUserWidget> UserButtonWidgetClass;

private:
	void SpawnButtons();
};
