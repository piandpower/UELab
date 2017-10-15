// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "FSProjectile.generated.h"

UCLASS()
class FSGAME_API AFSProjectile : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AFSProjectile();

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class UProjectileMovementComponent* projectMovement;

	/*UFUNCTION()
		void OnOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
