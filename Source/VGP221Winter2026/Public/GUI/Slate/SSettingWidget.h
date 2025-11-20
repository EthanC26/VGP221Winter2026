// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/GameHud.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VGP221WINTER2026_API SSettingWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingWidget)
		{}
		SLATE_ARGUMENT(TWeakObjectPtr<class AGameHud>, OwningHud)
	SLATE_END_ARGS()

	TWeakObjectPtr<class AGameHud> OwningHud;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnSettingsClicked() const;
	FReply OnQuitClicked() const;

	/*
	   --- Smart Pointer Cheat Sheet ---

	   Unique Pointer: TUniquePtr<T> = TUniquePtr<Int> Score;
	   - sole Ownership of an object
	   - cannot be copied, only moved
	   - automatically deallocates when it goes out of scope
	   -Resource Management for single Onwership scenarios

	   Shared Pointer: TSharedPtr<T> = TSharedPtr<Int> Score;
	   - multiple ownership of an object
	   - can be copied, incrementing reference count
	   - automatically deallocates when the last reference is gone
	   - Eg. UI Widgets, Game Objects shared across systems

	   weak Pointer: TWeakPtr<T> = TWeakPtr<Int> Score;
	   - non-owning reference to an object managed by TSharedPtr
	   - does not affect reference count
	   - Can be converted to TSharedPtr if the object is still valid
	   - Prevents circular references in shared ownership scenarios
	   - temporary access to memory

	   SoftObjectPtr: TSoftObjectPtr<T>: TSoftObjectPtr<UTexture> TextureRef;
	   - reference to an asset that may not be loaded in memory
	   - Can be serialized as and saved as a reference
	   - Loads the asset on demand
	   - Useful for large assets or optional content
	
	*/
};
