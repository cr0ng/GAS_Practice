// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/BarWidget.h"
#include "Components/ProgressBar.h"

void UBarWidget::SetProgressBarColor(FLinearColor Color)
{
    if (HPManaBar)
    {
        HPManaBar->SetFillColorAndOpacity(Color);
    }
}
