// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerControllerBase.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.h"

void ARPGPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	MyPlayer = Cast<ARPGCharacterBase>(GetPawn());
}


void ARPGPlayerControllerBase::MoveForward(float Value) 
{
	if (MyPlayer && Value)
	{
		MyPlayer->AddMovementInput(MyPlayer->GetActorForwardVector(), Value);
	}
}

void ARPGPlayerControllerBase::MoveRight(float Value) 
{
	if (MyPlayer && Value)
	{
		MyPlayer->AddMovementInput(MyPlayer->GetActorRightVector(), Value);
	}
}

void ARPGPlayerControllerBase::Jump()
{
	if (MyPlayer )
	{
		MyPlayer->Jump();
	}
}


void ARPGPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("Turn", this, &APlayerController::AddYawInput);
	InputComponent->BindAxis("LookUp", this, &APlayerController::AddPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ARPGPlayerControllerBase::Jump);
	InputComponent->BindAxis("MoveForward", this, &ARPGPlayerControllerBase::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARPGPlayerControllerBase::MoveRight);
		
	
	
}




