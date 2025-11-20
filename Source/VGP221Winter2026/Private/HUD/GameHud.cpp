// Fill out your copyright notice in the Description page of Project Settings.
#include "HUD/GameHud.h"
#include "Widgets/SWeakWidget.h"

void AGameHud::BeginPlay()
{
	Super::BeginPlay();

	//2. Slates method of Making UI
	ShowSettingMenu();

}

void AGameHud::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTex) return;

	//Canvas Dimensions
	float CanvasWidth = Canvas->ClipX;
	float CanvasHeight = Canvas->ClipY;
	FVector2D CanvasCenter(CanvasWidth * 0.5, CanvasHeight * 0.5);

	//Crosshair Dimensions
	float CrossHairWidth = CrosshairTex->GetSurfaceWidth();
	float CrossHairHeight = CrosshairTex->GetSurfaceHeight();
	float CrossHairScale = 5.0f;
	FVector2D CrossCenter(CrossHairWidth * 0.5, CrossHairHeight * 0.5);

	FVector2D CrosshairDrawPosition(CanvasCenter.X - CrossCenter.X, CanvasCenter.Y - CrossCenter.Y);
	FVector2D CrosshairSize(CrossHairWidth * CrossHairScale, CrossHairHeight * CrossHairScale);

	//Draw the Crosshair
	FCanvasTileItem CrosshairItem(CrosshairDrawPosition, CrosshairTex->GetResource(), CrosshairSize ,FLinearColor::White);
	CrosshairItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(CrosshairItem);
}

void AGameHud::ShowSettingMenu()
{

	SettingWidget = SNew(SSettingWidget).OwningHud(this);
	GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(SettingWidgetContanier, SWeakWidget).PossiblyNullContent(SettingWidget.ToSharedRef()));

	PlayerOwner->bShowMouseCursor = true;
	PlayerOwner->SetInputMode(FInputModeUIOnly());
}

void AGameHud::HideSettingMenu()
{
	GEngine->GameViewport->RemoveViewportWidgetContent(SettingWidgetContanier.ToSharedRef());

	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());
}
