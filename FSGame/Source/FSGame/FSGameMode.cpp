// Fill out your copyright notice in the Description page of Project Settings.

#include "FSGameMode.h"
#include "FSCharacter.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

AFSGameMode::AFSGameMode()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Game Init"));
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnObject(TEXT("Blueprint'/Game/BP/BP_MyCharacter'"));
	if (PlayerPawnObject.Object != NULL)
	{
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
	}

	//DefaultPawnClass = AFSCharacter::StaticClass();
}
