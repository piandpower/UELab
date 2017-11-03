// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (nullptr == ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR: ControlledTank IS NULL"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank Is %s"), *ControlledTank->GetName());
	}

}

ATank* ATankPlayerController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

