// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "GUI/GameMenuWidget.h"
#include "GUI/MainMenuWidget.h"
#include "GUI/Slate/SSettingWidget.h"
#include <GUI/GameOverWidget.h>
#include "GameHud.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2026_API AGameHud : public AHUD
{
	GENERATED_BODY()

protected: 
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTex;
public:

	virtual void BeginPlay() override;

	// 1. HUD method of Making UI
	virtual void DrawHUD() override;

	// 2. Slates method of Making UI
	TSharedPtr<class SSettingWidget> SettingWidget;
	TSharedPtr<class SWidget> SettingWidgetContanier;

	void ShowSettingMenu();
	void HideSettingMenu();

	// 3. UMG method of Making UI
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameMenuWidget> StartingGameWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameOverWidget> GameOverWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainMenuWidget> NewMainMenuWidgetClass;

	UUserWidget* GameMenuWidgetContanier;

	UGameOverWidget* GameOverWidgetContanier;

	UMainMenuWidget* MainMenuWidgetContanier;

	void toggleGameMenu(TSubclassOf<UGameMenuWidget> NewGameMenuWidget);

	void ToggleMainMenu(TSubclassOf<UMainMenuWidget> NewMainMenuuWidget);

	void ShowGameOverMenu(int32 FinalScore);

	void CloseMenu();

	void closeGameOverMenu();
};
