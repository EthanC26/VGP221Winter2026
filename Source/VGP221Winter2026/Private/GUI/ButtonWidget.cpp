// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/ButtonWidget.h"

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
}
