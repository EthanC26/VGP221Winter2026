// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2026_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* ButtonContainer;

	UPROPERTY(meta = (BlindWidget))
	UTextBlock* TitleText;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> UserButtonWidgetClass;

private:
	void SpawnButtons();
};
