// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectGameMode.h"
#include "MyProjectHUD.h"
#include "MyProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MyTriggerBox.h"
#include "UObject/ConstructorHelpers.h"

AMyProjectGameMode::AMyProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMyProjectHUD::StaticClass();
}

void AMyProjectGameMode::BeginPlay()
{
	UGameplayStatics::GetAllActorsOfClass(this, AMyTriggerBox::StaticClass(), Actors);

	for (AActor* item : Actors)
	{
		AMyTriggerBox* items = Cast<AMyTriggerBox>(item);
		items->StartTimer();
	}
}
