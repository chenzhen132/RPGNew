// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.h"
#include "RPGPlayerControllerBase.generated.h"
/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
public:
	virtual void BeginPlay() override;
	void MoveForward(float Value) ;
	void MoveRight(float Value) ;
	void Jump() ;
	//virtual void PlayerTick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	ARPGCharacterBase* MyPlayer;
};
