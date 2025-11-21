#pragma once

#include "CoreMinimal.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * Main Menu Widget
 */
UCLASS()
class VGP221WINTER2026_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	// Container for buttons
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* ButtonContainer;

	// Main title text
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	// Button widget class to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> UserButtonWidgetClass;

private:
	// Spawns buttons dynamically
	void SpawnButtons();
};
