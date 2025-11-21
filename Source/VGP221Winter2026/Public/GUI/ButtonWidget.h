// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "ButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2026_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonText;

	UFUNCTION()
	void SetButtonText(int value);

	UFUNCTION()
	void OnButtonClicked();

private:
	int Num = -1;

};
