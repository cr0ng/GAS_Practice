// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/PlayerWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UPlayerWidget::UpdateCurrent_Implementation(float InValue)
{
	Current->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	ManaBar->SetPercent(InValue/MaxValue);
}

void UPlayerWidget::UpdateMax_Implementation(float InValue)
{
	Max->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	MaxValue = InValue;
}
