// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "JumperGameMode.h"
#include "JumperCharacter.h"

AJumperGameMode::AJumperGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
