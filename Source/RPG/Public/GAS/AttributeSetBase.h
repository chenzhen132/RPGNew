// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/GameInstance.h"
#include "AttributeSetBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedDelegate, float,CurrentValue , float, MaxValue);

/**
 * 
 */

UCLASS()
class RPG_API UAttributeSetBase : public UAttributeSet 
{
	GENERATED_BODY()
public:
	UAttributeSetBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributSet")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributSet")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributSet")
	FGameplayAttributeData Mp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributSet")
	FGameplayAttributeData MaxMp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributSet")
	FGameplayAttributeData Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributSet")
	FGameplayAttributeData MaxStrength;


	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnHpChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnMpChanged;

	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedDelegate OnStrengthChanged;

};