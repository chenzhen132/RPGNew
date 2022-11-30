// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"

UAttributeSetBase::UAttributeSetBase():
	Health(100.f), MaxHealth(100.f), Mp(100.f), MaxMp(100.f),
	Strength(100.f), MaxStrength(100.f)
{
}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(
		UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.f, Health.GetBaseValue()));
		MaxHealth.SetCurrentValue(FMath::Clamp(MaxHealth.GetCurrentValue(), 0.f, MaxHealth.GetCurrentValue()));
		OnHpChanged.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(
		UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mp)))
	{
		Mp.SetCurrentValue(FMath::Clamp(Mp.GetCurrentValue(), 0.f, Mp.GetBaseValue()));
		MaxMp.SetCurrentValue(FMath::Clamp(MaxMp.GetCurrentValue(), 0.f, MaxMp.GetCurrentValue()));
		OnMpChanged.Broadcast(Mp.GetCurrentValue(), MaxMp.GetCurrentValue());
	}
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(
		UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength)))
	{
		Strength.SetCurrentValue(FMath::Clamp(Strength.GetCurrentValue(), 0.f, Strength.GetBaseValue()));
		MaxStrength.SetCurrentValue(FMath::Clamp(MaxStrength.GetCurrentValue(), 0.f, MaxStrength.GetCurrentValue()));
		OnStrengthChanged.Broadcast(Strength.GetCurrentValue(), MaxStrength.GetCurrentValue());
	}
}
