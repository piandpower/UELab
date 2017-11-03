// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LEARNTANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank(); // 获取控制的坦克

	void AimToTarget(); // 瞄准

	bool GetSightRayHitLocation(FVector &OutHitLocation);	// 获取射线撞到的位置

	//使用射线 找撞击点
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation);

private:

	float CrosshairXLocation = 0.5f;
	float CrosshairYLocation = 0.3f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.0f;

};
