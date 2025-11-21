// Fill out your copyright notice in the Description page of Project Settings.

#include "GUI/MainMenuButtonWidget.h"
#include "GUI/MainMenuWidget.h"


void UMainMenuWidget::NativeConstruct()
{
}

void UMainMenuWidget::SpawnButtons()
{
	if (!ButtonContainer || !UserButtonWidgetClass) return;

	TArray<FString> ButtonNames = { TEXT("Restart"), TEXT("Main Menu"), TEXT("Quit") };

	for (int i = 0; i < ButtonNames.Num(); i++)
	{
		UUserWidget* Widget = CreateWidget(this, UserButtonWidgetClass);
		ButtonContainer->AddChild(Widget);

		UMainMenuButtonWidget* ButtonWidget = Cast<UMainMenuButtonWidget>(Widget);
		if (ButtonWidget)
		{
			ButtonWidget->SetButtonText(ButtonNames[i]);; // Set button number starting from 1
		}

	}
}
