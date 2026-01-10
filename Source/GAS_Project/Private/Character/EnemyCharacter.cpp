// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameAbilitySystem/AttributeSet/EnemyAttributeSet.h"
#include "Components/WidgetComponent.h"
#include "Interface/BarResource.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	//EnemyAttributeSet = CreateDefaultSubobject<UEnemyAttributeSet>(TEXT("EnemyAttributeSet"));
	
	HPWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPWidget"));
	HPWidgetComponent->SetupAttachment(GetMesh());
	HPWidgetComponent->SetRelativeLocation(FVector(0, 0, 120.f));
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	if (EnemyAttributeSet)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyAttributeSet"));
		if (HPWidgetComponent && HPWidgetComponent->GetWidget())
		{
			if (HPWidgetComponent->GetWidget()->Implements<UBarResource>())
			{
				IBarResource::Execute_UpdateMaxHealth(HPWidgetComponent->GetWidget(), EnemyAttributeSet->GetMaxHealth());
				IBarResource::Execute_UpdateCurrentHealth(HPWidgetComponent->GetWidget(), EnemyAttributeSet->GetHealth());
			}
		}
	}
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

