
#include "GUI/MainMenuButtonWidget.h"
#include "HUD/GameHud.h"
void UMainMenuButtonWidget::SetButtonText(const FString& TextValue)
{
	if (ButtonText)
	{
		ButtonText->SetText(FText::FromString(TextValue));
	}
	Button->OnClicked.AddDynamic(this, &UMainMenuButtonWidget::OnButtonClicked);
}

void UMainMenuButtonWidget::OnButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Main Menu Button Clicked: %s"), *ButtonText->GetText().ToString());
	if (ButtonText->GetText().ToString() == "Play")
	{
		// Logic to start the game
		UE_LOG(LogTemp, Warning, TEXT("Starting Game..."));
		 
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		HUD->CloseMainMenu();
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

