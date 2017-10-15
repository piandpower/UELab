// Fill out your copyright notice in the Description page of Project Settings.

#include "FSProjectile.h"
#include "Engine/Engine.h"
#include "UObject/UObjectGlobals.h"

// Sets default values
AFSProjectile::AFSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	//CollisionComp->OnComponentBeginOverlap.__Internal_AddDynamic(this, &AFSProjectile::OnOverlap);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	RootComponent = CollisionComp;

	projectMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectMove"));
	projectMovement->UpdatedComponent = CollisionComp;
	projectMovement->InitialSpeed = 3000.0f;
	projectMovement->MaxSpeed = 3000.0f;
	projectMovement->bRotationFollowsVelocity = true;
	projectMovement->bShouldBounce = true;

	InitialLifeSpan = 2.0f;
}

//void AFSProjectile::OnOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	if (OtherActor != NULL && OtherActor != this && OtherComp != NULL)
//	{
//		OtherComp->AddImpulseAtLocation(100.0f * GetVelocity(), GetActorLocation());
//		Destroy();
//	}
//}

// Called when the game starts or when spawned
void AFSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

