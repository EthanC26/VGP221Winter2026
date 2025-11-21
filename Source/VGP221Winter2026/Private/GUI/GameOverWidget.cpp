// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameOverWidget.h"
#

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetUpFinalScore(2);

	SpawnButtons();
}

void UGameOverWidget::SetUpFinalScore(int32 FinalScore)
{
	if (!FinalScoreText) return;

	FinalScoreText->SetText(FText::FromString(FString::Printf(TEXT("Final Score: %d"), FinalScore)));

}

void UGameOverWidget::SpawnButtons()
{
	if (!ButtonContanier|| !UserButtonWidgetClass) return;

	TArray<FString> ButtonNames = { TEXT("Restart"), TEXT("Main Menu"), TEXT("Quit") };

	for (int i = 0; i < ButtonNames.Num(); i++)
	{
		UUserWidget* Widget = CreateWidget(this, UserButtonWidgetClass);
		ButtonContanier->AddChild(Widget);

		UGameOverButtonWidget* ButtonWidget = Cast<UGameOverButtonWidget>(Widget);
		if (ButtonWidget)
		{
		   ButtonWidget->SetButtonText(ButtonNames[i]);; // Set button number starting from 1
		}
	
	}
}
