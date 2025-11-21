// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameMenuWidget.h"
#include "HUD/GameHud.h"

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
	if (!HealthBar)
	{
		UE_LOG(LogTemp, Warning, TEXT("HealthBar is null! UpdateHealthBar skipped."));
		return;
	}
	HealthBar->SetPercent(HealthPercent);

	if (HealthBar->Percent <= 0.0)
	{

		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		AGameHud* HUD = Cast<AGameHud>(PC->GetHUD());
		if (!HUD) return;

		HUD->ShowGameOverMenu(10);
	}
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
