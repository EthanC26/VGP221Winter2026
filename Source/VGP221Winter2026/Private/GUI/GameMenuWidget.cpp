// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameMenuWidget.h"

void UGameMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateHealthBar(1.0f);
	SetScoreText(0);
	SetTimerText(60);

	//example of spawning user widgets dynamically
	for (int i = 0; i < 4; i++)
	{
		UUserWidget* Widget = CreateWidget(this, UserButtonWidgetClass);
		ButtonContanier->AddChild(Widget);

		UButtonWidget* ButtonWidget = Cast<UButtonWidget>(Widget);
		ButtonWidget->SetButtonText(i);
	}

}

void UGameMenuWidget::UpdateHealthBar(float HealthPercent)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(HealthPercent);
}

void UGameMenuWidget::SetScoreText(int amount)
{
	if (!ScoreText) return;

	UIScore += amount;
	ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), UIScore)));
}

void UGameMenuWidget::SetTimerText(int timer)
{
	if (!TimerText) return;

	TimerText->SetText(FText::FromString(FString::Printf(TEXT("Timer : %d"), timer)));
}
