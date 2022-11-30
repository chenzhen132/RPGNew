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
	// ���ý�����뾶
	GetCapsuleComponent()->InitCapsuleSize(42.f, 95.0f);

	// ���ﲻ�������������ת
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// ��ת�����˶�
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// ����һ��SpringArm������ӵ����������ʹ�ÿ������������������ת
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; 	
	CameraBoom->bUsePawnControlRotation = true; 

	// ����һ�������������ӵ�SpringArm���
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


