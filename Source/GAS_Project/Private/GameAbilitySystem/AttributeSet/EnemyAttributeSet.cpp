// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilitySystem/AttributeSet/EnemyAttributeSet.h"
#include "GameplayEffectExtension.h"

UEnemyAttributeSet::UEnemyAttributeSet()
{
	InitHealth(100.0f);
}

void UEnemyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		UE_LOG(LogTemp, Log, TEXT("Health 변경: %.1f -> %.1f"), GetHealth(), NewValue)

			// 헬스가 최대를 넘지 않고 음수가 되지 않게 하기

	}
}

void UEnemyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		UE_LOG(LogTemp, Log, TEXT("현재 Health : %.1f"), GetHealth());
		if (GetHealth() <= 0.0f)
		{
			UE_LOG(LogTemp, Log, TEXT("사망"));
		}
	}
}
