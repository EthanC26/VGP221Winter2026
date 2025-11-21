// Fill out your copyright notice in the Description page of Project Settings.

#include "GUI/ButtonWidget.h"
#include "HUD/GameHud.h"

void UButtonWidget::SetButtonText(int value)
{
	if (!Button || !ButtonText) return;

	Num = value;
	ButtonText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Num)));
	Button->OnClicked.AddDynamic(this, &UButtonWidget::OnButtonClicked);
}
void UButtonWidget::OnButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Button %d Clicked"), Num);

	if (Num == 1)
	{
		//get player controller
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		//get hud
		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		HUD->ShowSettingMenu();

	}

	if (Num == 0)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		HUD->ShowGameOverMenu(10);
	}

	if (Num == 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("Switching to Main Menu"));

		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		if (HUD->NewMainMenuWidgetClass)
		{
			HUD->ToggleMainMenu(HUD->NewMainMenuWidgetClass);
		}
	}
}
