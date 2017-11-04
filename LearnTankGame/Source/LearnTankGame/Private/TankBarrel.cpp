// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"


void UTankBarrel::MoveBarrel(FVector AimDirection)
{
	FRotator CurrentRotation = GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();


	float ChangePitch = AimRotation.Pitch - CurrentRotation.Pitch;
	float RelativeSpeed = FMath::Clamp<float>(ChangePitch, -1, 1);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotationPitch = RotationChange + CurrentRotation.Pitch;

	SetRelativeRotation(FRotator(NewRotationPitch, 0, 0));
}
