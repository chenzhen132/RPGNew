// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GAS/AttributeSetBase.h"
#include "GAS/GameplayAbilityBase.h"

ARPGCharacterBase::ARPGCharacterBase()
{
	// 设置胶囊体半径
	GetCapsuleComponent()->InitCapsuleSize(42.f, 95.0f);

	// 人物不跟随控制器的旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 旋转朝向运动
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// 创建一个SpringArm组件连接到根组件，并使用控制器控制摄像机的旋转
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; 	
	CameraBoom->bUsePawnControlRotation = true; 

	// 创建一个摄像机组件连接到SpringArm组件
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false; 

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>(TEXT("AbilitySet"));

}

//////////////////////////////////////////////////////////////////////////
// Input

void ARPGCharacterBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//Bind Action
	check(PlayerInputComponent);
	bool bIsPlayer = GetController()->IsPlayerController();
}


FGamePlayAbilityInfo  ARPGCharacterBase::GetAbility(TSubclassOf<UGameplayAbilityBase> Ability)
{
	if (Ability && AbilitySystemComp)
	{
		AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(Ability,1));
		AbilitySystemComp->InitAbilityActorInfo(this, this);
		UGameplayAbilityBase* AbilityIns = Ability->GetDefaultObject<UGameplayAbilityBase>();
		if (Ability)
		{
			return AbilityIns->GetAbilityInfo();
		}
	}
	return FGamePlayAbilityInfo();
}

void ARPGCharacterBase::AddGameplayTag(FGameplayTag TagToAdd)
{
	GetAbilitySystemComponent()->AddLooseGameplayTag(TagToAdd);
}

void ARPGCharacterBase::RemoveGameplayTag(FGameplayTag TagToRemove)
{
}


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}


