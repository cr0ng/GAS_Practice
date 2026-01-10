// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/BarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UBarWidget::SetProgressColor(FLinearColor InColor)
{
	StatusProgressBar->SetFillColorAndOpacity(InColor);
}

void UBarWidget::UpdateCurrent_Implementation(float InValue)
{
	Current->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	CurrentValue = InValue;
	StatusProgressBar->SetPercent(CurrentValue / MaxValue);
}

void UBarWidget::UpdateMax_Implementation(float InValue)
{
	Max->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	MaxValue = InValue;
	StatusProgressBar->SetPercent(CurrentValue / MaxValue);
}
