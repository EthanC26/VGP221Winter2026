// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/MainMode.h"


void AMainMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	//1. to pPRint Screen
	//display a debug message for five seconds
	//the -1 "key" value means it will only appear once
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Welcome to VGP221!"));

	//2. to Print console
	UE_LOG(LogTemp, Warning, TEXT("TEEHEE"));

	//3. printing values to console
	int TestValue = 40;
	float TestFloat = 3.14159f;
	UE_LOG(LogTemp, Warning, TEXT("TestNumber: %i, TestFlaot: %f"), TestValue, TestFloat);

	//4. modern way of debugging values
	UE_LOGFMT(LogTemp, Warning, "TestNumber: {0}, TestFlaot: {1} CoolGuy: {2}", TestValue, TestFloat, "Erhan");
	
}