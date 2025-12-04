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
	FString ButtonLabel = ButtonText->GetText().ToString();
	UE_LOG(LogTemp, Warning, TEXT("Game Over Button Clicked: %s"), *ButtonLabel);

	
	 if (ButtonText->GetText().ToString() == "Main Menu")
	{
		// Logic to go to main menu
		UE_LOG(LogTemp, Warning, TEXT("Returning to Main Menu..."));
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			// Hide mouse cursor and reset input
			PC->bShowMouseCursor = false;
			PC->SetInputMode(FInputModeGameOnly());
		}

		// Reload level
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
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
