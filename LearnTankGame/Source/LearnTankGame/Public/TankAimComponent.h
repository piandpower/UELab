// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

UENUM()
enum class EFireState :uint8
{
	Reloading,
	Aiming,
	Locked,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNTANKGAME_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable,Category = "Setup")
		void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Gmaeplay")
		void Fire();
	
	void AimAt(FVector HitLocation);

	UTankTurret* Turret = nullptr;

	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
		float TankReloadTime = 3.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		float LaunchSpeed = 10000.0f;

	UPROPERTY(EditAnywhere,Category = "Setup")
		TSubclassOf<AProjectile> ProjectileType;

	UPROPERTY(BlueprintReadOnly)
		EFireState FireState = EFireState::Aiming;

private:
	double LastFireTime = 0;


};

