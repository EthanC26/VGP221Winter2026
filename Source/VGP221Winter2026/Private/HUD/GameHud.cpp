// Fill out your copyright notice in the Description page of Project Settings.
#include "HUD/GameHud.h"
#include "Widgets/SWeakWidget.h"

void AGameHud::BeginPlay()
{
	Super::BeginPlay();

	//2. Slates method of Making UI
	//ShowSettingMenu();

	//3. UMG method of Making UI
	toggleGameMenu(StartingGameWidget);
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

void AGameHud::toggleGameMenu(TSubclassOf<UGameMenuWidget> NewGameMenuWidget)
{
	if (GameMenuWidgetContanier)
	{
		GameMenuWidgetContanier->RemoveFromParent();
		GameMenuWidgetContanier = nullptr;
	}

	GameMenuWidgetContanier = CreateWidget<UGameMenuWidget>(GetWorld(), NewGameMenuWidget);
	GameMenuWidgetContanier->AddToViewport();
}
void AGameHud::ShowGameOverMenu(int32 FinalScore)
{
    // 1️⃣ Hide existing game menu if it exists
    if (GameMenuWidgetContanier)
    {
        GameMenuWidgetContanier->RemoveFromParent();
        GameMenuWidgetContanier = nullptr;
    }

    // 2️⃣ Load the Game Over widget Blueprint
    TSubclassOf<UGameOverWidget> GameOverWidgetClass = LoadClass<UGameOverWidget>(
        nullptr,
        TEXT("/Game/GUI/WBP_GameOver.WBP_GameOver_C")
    );

    if (!GameOverWidgetClass) return;

    // 3️⃣ Create the Game Over widget
    GameOverWidgetContanier = CreateWidget<UGameOverWidget>(GetWorld(), GameOverWidgetClass);
    if (!GameOverWidgetContanier) return;

    // 4️⃣ Add to viewport and set final score
    GameOverWidgetContanier->AddToViewport();
    GameOverWidgetContanier->SetUpFinalScore(FinalScore);

    // 5️⃣ Show mouse cursor and set input mode to UI only
    if (PlayerOwner)
    {
        PlayerOwner->bShowMouseCursor = true;
        PlayerOwner->SetInputMode(FInputModeUIOnly());
    }
}


