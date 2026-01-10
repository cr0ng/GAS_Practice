// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilitySystem/AttributeSet/PlayerAttributeSet.h"
#include "GameplayEffectExtension.h"

UPlayerAttributeSet::UPlayerAttributeSet()
{
	InitMana(100.0f);
	InitMaxMana(100.0f);

}

// 값 검증 및 제한 부분(수학적 처리)
void UPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetManaAttribute())
	{
		UE_LOG(LogTemp,Log,TEXT("Mana 변경: %.1f -> %.1f"),GetMana(),NewValue)

	// 마나가 최대를 넘지 않고 음수가 되지 않게 하기

	}
}

// 게임 로직 실행 부분
void UPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		UE_LOG(LogTemp, Log, TEXT("현재 Mana : %.1f"), GetMana());
		if (GetMana() <= 0.0f)
		{
			UE_LOG(LogTemp, Log, TEXT("마나가 0"));
		}
	}
}


