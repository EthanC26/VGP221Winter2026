// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/Slate/SSettingWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSettingWidget::Construct(const FArguments& InArgs)
{
	OwningHud = InArgs._OwningHud;

	const FMargin ContentPadding(500.0f, 300.0f);

	//settings Config
	const FText TitleText = FText::FromString("Settings Menu");
	FSlateFontInfo TitleFont = FCoreStyle::Get().GetFontStyle("EmbassedText");
	TitleFont.Size = 60;

	//button Config
	const FMargin ButtonPadding(10.0f);
	FSlateFontInfo ButtonFont = TitleFont;
	ButtonFont.Size = 40;

	//Resume Button Config
	const FText ResumeText = FText::FromString("RESUME");
	//Quit Button Config
	const FText QuitText = FText::FromString("QUIT");
	//Settings Button Config
	const FText SetttingsText = FText::FromString("SETTINGS");

	
	ChildSlot
		[
			// Populate the widget
			SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)

				[
					SNew(SImage)
						.ColorAndOpacity(FColor::Black)
				]
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(ContentPadding)
				[
					SNew(SVerticalBox)
						// title text
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
								.Text(TitleText)
								.Font(TitleFont)
								.Justification(ETextJustify::Center)
						]
						// Resume Button
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							SNew(SButton)
								.OnClicked(this, &SSettingWidget::OnResumeClicked)
								[
									SNew(STextBlock)
										.Text(ResumeText)
										.Font(ButtonFont)
										.Justification(ETextJustify::Center)
								]
						]
						// Settings Button
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							SNew(SButton)
								.OnClicked(this, &SSettingWidget::OnSettingsClicked)
								[
									SNew(STextBlock)
										.Text(SetttingsText)
										.Font(ButtonFont)
										.Justification(ETextJustify::Center)
								]
						]
						// Quit Button
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							SNew(SButton)
								.OnClicked(this, &SSettingWidget::OnQuitClicked)
								[
									SNew(STextBlock)
										.Text(QuitText)
										.Font(ButtonFont)
										.Justification(ETextJustify::Center)
								]
						]
				]
		];
}
FReply SSettingWidget::OnResumeClicked() const
{
	if (OwningHud.IsValid())
	{
		OwningHud->HideSettingMenu();
	}
	return FReply::Handled();

}
FReply SSettingWidget::OnSettingsClicked() const
{
	return FReply::Handled();
}
FReply SSettingWidget::OnQuitClicked() const
{
	if (OwningHud.IsValid())
	{	
			if (APlayerController* PC = OwningHud->PlayerOwner)
			{
				PC->ConsoleCommand("quit");
			}	
	}
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
