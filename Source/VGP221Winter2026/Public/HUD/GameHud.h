// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "GUI/Slate/SSettingWidget.h"
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
};
