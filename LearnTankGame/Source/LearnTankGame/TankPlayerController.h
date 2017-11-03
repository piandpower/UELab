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

	ATank* GetControlledTank(); // ��ȡ���Ƶ�̹��

	void AimToTarget(); // ��׼

	bool GetSightRayHitLocation(FVector &OutHitLocation);	// ��ȡ����ײ����λ��

	//ʹ������ ��ײ����
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation);

private:

	float CrosshairXLocation = 0.5f;
	float CrosshairYLocation = 0.3f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.0f;

};
