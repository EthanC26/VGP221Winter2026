// Fill out your copyright notice in the Description page of Project Settings.

#include "GUI/MainMenuWidget.h"
#include "GUI/MainMenuButtonWidget.h"


void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SpawnButtons();
}

void UMainMenuWidget::SpawnButtons()
{
	if (!ButtonContainer || !UserButtonWidgetClass) return;

	TArray<FString> ButtonNames = {TEXT("Play"), TEXT("Quit") };

	for (int i = 0; i < ButtonNames.Num(); i++)
	{
		UUserWidget* Widget = CreateWidget(this, UserButtonWidgetClass);
		ButtonContainer->AddChild(Widget);

		UMainMenuButtonWidget* ButtonWidget = Cast<UMainMenuButtonWidget>(Widget);
		if (ButtonWidget)
		{
			ButtonWidget->SetButtonText(ButtonNames[i]); // Set button number starting from 1
		}

	}
}
