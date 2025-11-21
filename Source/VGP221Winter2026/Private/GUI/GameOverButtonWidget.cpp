// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameOverButtonWidget.h"
#include "HUD/GameHud.h"

void UGameOverButtonWidget::SetButtonText(const FString& TextValue)
{
	if (ButtonText)
	{
		ButtonText->SetText(FText::FromString(TextValue));
	}

	Button->OnClicked.AddDynamic(this, &UGameOverButtonWidget::OnButtonClicked);
}

void UGameOverButtonWidget::OnButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over Button Clicked: %s"), *ButtonText->GetText().ToString());

	if (ButtonText->GetText().ToString() == "Restart")
	{
		// Logic to restart the game
		UE_LOG(LogTemp, Warning, TEXT("Restarting Game..."));
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		HUD->closeGameOverMenu();
		HUD->toggleGameMenu(HUD->StartingGameWidget);
	}
	else if (ButtonText->GetText().ToString() == "Main Menu")
	{
		// Logic to go to main menu
		UE_LOG(LogTemp, Warning, TEXT("Returning to Main Menu..."));
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		HUD->closeGameOverMenu();
		HUD->ToggleMainMenu(HUD->NewMainMenuWidgetClass);
	}
	else if (ButtonText->GetText().ToString() == "Quit")
	{
		// Logic to quit the game
		UE_LOG(LogTemp, Warning, TEXT("Quitting Game..."));
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		{
			PC->ConsoleCommand("quit");
		}
	}
}
