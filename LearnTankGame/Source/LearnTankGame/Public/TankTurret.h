// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LEARNTANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSscond = 20.0f;

	void MoveTurret(FVector AimDirection);

	float GetChangeYaw();

private:
	float ChangeYaw;
	
};
