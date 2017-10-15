// Fill out your copyright notice in the Description page of Project Settings.

#include "FSCharacter.h"
#include "Engine/Engine.h"
#include "UObject/UObjectGlobals.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFSCharacter::AFSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	MeshHand->SetOnlyOwnerSee(true);
	MeshHand->SetOwnerNoSee(false);
	//MeshHand->AttachToComponent(RootComponent);
	//MeshHand->RelativeLocation = FVector(0, 0, -150.0f);
	MeshHand->bCastDynamicShadow = false;
	MeshHand->CastShadow = false;

}

// Called when the game starts or when spawned
void AFSCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("FSCharacter"));
}

// Called every frame
void AFSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, TEXT("BindInput"));
	//绑定前后左右移动
	PlayerInputComponent->BindAxis("MoveForward", this, &AFSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFSCharacter::MoveRight);
	//绑定鼠标转动视角
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//绑定跳跃
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//开火
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFSCharacter::OnFire);

}

//前进后退
void AFSCharacter::MoveForward(float val)
{
	if (val == 0.0f)
		return;
	const FRotator Rotation = GetActorRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);
	//获得面向方向向量
	const FVector Dir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//朝这个方向移动
	AddMovementInput(Dir, val);
}

//左右移动
void AFSCharacter::MoveRight(float val)
{
	if (val == 0.0f)
		return;
	const FRotator Rotation = GetActorRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);
	//获得面向方向向量
	const FVector Dir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//朝这个方向移动
	AddMovementInput(Dir, val);
}

void AFSCharacter::OnFire()
{
	if (ProjectileCLass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation();
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);
		UWorld* const World = GetWorld();
		if (NULL != World)
		{
			World->SpawnActor<AFSProjectile>(ProjectileCLass, SpawnLocation, SpawnRotation);
		}

		if (FireSound != NULL)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		if (FireAnimation != NULL)
		{
			UAnimInstance* AnimInstance = MeshHand->GetAnimInstance();
			if (AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.0f);
			}
		}
	}
}

