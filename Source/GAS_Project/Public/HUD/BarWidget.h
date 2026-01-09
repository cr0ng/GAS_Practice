// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BarWidget.generated.h"

/**
 * 
 */

class UProgressBar;
class UTextBlock;

UCLASS()
class GAS_PROJECT_API UBarWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void UpdateCurrent(float InValue);
	void UpdateMax(float InValue);

	UFUNCTION(BlueprintCallable)
	void SetProgressBarColor(FLinearColor Color);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HPManaBar = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Current = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Max = nullptr;
	
};
