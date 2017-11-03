// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();
	if (nullptr == ControlledTank || nullptr == PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR: ControlledTank IS NULL"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank Is %s, PLayer Tank %s"), *ControlledTank->GetName(), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return PlayerTank;
}
