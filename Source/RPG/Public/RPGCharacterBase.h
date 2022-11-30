// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GAS/GameplayAbilityBase.h"
#include "RPGCharacterBase.generated.h"

UCLASS()
class RPG_API ARPGCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	//公开SpringArm以及Camera到蓝图
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComp;

public:
	ARPGCharacterBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attribute")
	class UAttributeSetBase* AttributeSet;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	//获取Camera组件
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	FGamePlayAbilityInfo GetAbility(TSubclassOf<UGameplayAbilityBase> Ability);

	UFUNCTION(BlueprintCallable,Category="CharacterBase")
	void AddGameplayTag(FGameplayTag TagToAdd);
	UFUNCTION(BlueprintCallable,Category="CharacterBase")
	void RemoveGameplayTag(FGameplayTag TagToRemove);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CharacterBase")
	FGameplayTag FullSkillTag;
};
