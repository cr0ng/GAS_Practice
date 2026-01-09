// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */

class UProgressBar;
class UTextBlock;

UCLASS()
class GAS_PROJECT_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:


protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ManaBar = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Current = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Max = nullptr;

private:
	float MaxValue = 1.0f;
	
};
