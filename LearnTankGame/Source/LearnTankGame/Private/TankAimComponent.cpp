// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (Barrel == nullptr || ProjectileType == nullptr)
		return;
	if (FPlatformTime::Seconds() - LastFireTime > TankReloadTime)
	{
		FireState = EFireState::Reloading;
		return;
	}

	if (FMath::Abs(Turret->GetChangeYaw()) > 3)
	{
		FireState = EFireState::Aiming;
		return;
	}
	FireState = EFireState::Locked;

}

void UTankAimComponent::Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimComponent::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
	bool bIsReload = (FPlatformTime::Seconds() - LastFireTime) > TankReloadTime;

	if (Barrel == nullptr || ProjectileType == nullptr || !bIsReload)
		return;

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileType,
		Barrel->GetSocketLocation(FName("FireLocation")),
		Barrel->GetSocketRotation(FName("FireLocation"))
		);
	Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimComponent::AimAt(FVector HitLocation)
{
	if (Turret == nullptr || Barrel == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("NULL Turret Barrel Return"));
		return;
	}

	FVector FireVector;
	FVector StartLocation = Barrel->GetSocketLocation(FName("FireLocation"));

	bool bHaveSolution = false;
	bHaveSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		FireVector,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveSolution)
	{
		//通知炮塔和炮管转向
		Turret->MoveTurret(FireVector.GetSafeNormal());
		Barrel->MoveBarrel(FireVector.GetSafeNormal());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("bHaveSolution is Flase"));
	}

}

