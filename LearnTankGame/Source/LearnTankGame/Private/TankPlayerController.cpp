// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"


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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimToTarget();
}

ATank* ATankPlayerController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimToTarget()
{
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation)
{
	//获取屏幕大小
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector WorldLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,WorldLocation,WorldDirection))
	{
		//使用射线 找撞击点
		GetLookVectorHitLocation(WorldDirection, OutHitLocation);
		return true;
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation)
{
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;

	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector::ZeroVector;
	return false;
}

