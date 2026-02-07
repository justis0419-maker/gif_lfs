// Copyright Epic Games, Inc. All Rights Reserved.

#include "ch030206GameMode.h"
#include "ch030206PlayerController.h"
#include "ch030206Character.h"
#include "UObject/ConstructorHelpers.h"

Ach030206GameMode::Ach030206GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = Ach030206PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}