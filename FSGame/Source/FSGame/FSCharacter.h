// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FSProjectile.h"
#include "Components/SkeletalMeshComponent.h"
#include "FSCharacter.generated.h"

UCLASS()
class FSGAME_API AFSCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AFSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		FVector GunOffset;
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		//class AFSProjectile ProjectileCLass;
		TSubclassOf<class AFSProjectile> ProjectileCLass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		USoundBase* FireSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		UAnimMontage* FireAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		class USkeletalMeshComponent* MeshHand;
private:



	//前进后退
	void MoveForward(float val);
	//左右移动
	void MoveRight(float val);
	//开火
	void OnFire();
};
