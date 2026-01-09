// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/EnemyWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UEnemyWidget::UpdateCurrent_Implementation(float InValue)
{
	UE_LOG(LogTemp, Log, TEXT("UpdateCurrentHP_Implementation 실행"));
	Current->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	HPBar->SetPercent(InValue / MaxValue);
}

void UEnemyWidget::UpdateMax_Implementation(float InValue)
{
	Max->SetText(FText::AsNumber(FMath::RoundToInt(InValue)));
	MaxValue = InValue;
}
