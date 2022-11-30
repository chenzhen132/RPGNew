// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbilityBase.generated.h"

class UGameplayAbilityBase;
/**
 * 
 */
UENUM(BlueprintType)
enum class ECostType :uint8
{
	Hp,Mp,Strength
};

USTRUCT(BlueprintType)
struct FGamePlayAbilityInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Ability)
	float Cooldown;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Ability)
	float Cost;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Ability)
	ECostType CostType;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Ability)
	UMaterialInstance* IconMat;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Ability)
	TSubclassOf<UGameplayAbilityBase> AbilityClass;

	FGamePlayAbilityInfo();
	FGamePlayAbilityInfo(float Cooldown, float Cost, ECostType CostType, UMaterialInstance* IconMat, TSubclassOf<UGameplayAbilityBase> AbilityClass);

};


UCLASS()
class RPG_API UGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Ability)
	UMaterialInstance* IconMat;

	//UFUNCTION(BlueprintCallable,Category = "Ability")
	FGamePlayAbilityInfo GetAbilityInfo() const;
};