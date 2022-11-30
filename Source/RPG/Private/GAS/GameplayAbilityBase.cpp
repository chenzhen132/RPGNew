// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GameplayAbilityBase.h"

FGamePlayAbilityInfo::FGamePlayAbilityInfo():
Cooldown(0.0f),Cost(0.0f),CostType(ECostType::Mp),
IconMat(nullptr),AbilityClass(nullptr)
{}

FGamePlayAbilityInfo::FGamePlayAbilityInfo(float Cooldown_Skill, float Cost_Skill, ECostType CostType_Skill,
	UMaterialInstance* InconMat_Skill, TSubclassOf<UGameplayAbilityBase> AbilityClass_Skill):
Cooldown(Cooldown_Skill),Cost(Cost_Skill),CostType(CostType_Skill),IconMat(InconMat_Skill),AbilityClass(nullptr)
{}

FGamePlayAbilityInfo UGameplayAbilityBase::GetAbilityInfo() const
{
	UGameplayEffect* CooldownEffect = GetCooldownGameplayEffect();
	UGameplayEffect* Costffect = GetCostGameplayEffect();
	float Cooldown = 0;
	float Cost = 0;
	ECostType CostType = ECostType::Mp;
	if (CooldownEffect && Costffect)
	{
		CooldownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(1,Cooldown);
		if (Costffect->Modifiers.Num() > 0)
		{
			FGameplayModifierInfo CostEffectModifierInfo = Costffect->Modifiers[0];
			CostEffectModifierInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(1,Cost);

			FGameplayAttribute CostAttribute = CostEffectModifierInfo.Attribute;
			FString CostAttributeName = CostAttribute.AttributeName;
			if (CostAttributeName == "Hp")
			{
				CostType = ECostType::Hp;
			}
			if (CostAttributeName == "Mp")
			{
				CostType = ECostType::Mp;
			}
			if (CostAttributeName == "Strength")
			{
				CostType = ECostType::Strength;
			}
		}
		return FGamePlayAbilityInfo(Cooldown,Cost,CostType,IconMat,GetClass());
	}
	return FGamePlayAbilityInfo();
}
