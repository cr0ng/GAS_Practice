// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/BarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UBarWidget::UpdateCurrent_Implementation(float InValue)
{
	Current->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	StatusProgressBar->SetPercent(InValue / MaxValue);
}

void UBarWidget::UpdateMax_Implementation(float InValue)
{
	Max->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	MaxValue = InValue;
}
