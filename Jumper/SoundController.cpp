// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "SoundController.h"


// Sets default values
ASoundController::ASoundController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/* play sound */
void ASoundController::PlayMusic() {
    if (Sound && SoundComponent)
        UGameplayStatics::PlaySound2D(SoundComponent,Sound, 1.0f, 1.0f, 0.0f);
}

// Called when the game starts or when spawned
void ASoundController::BeginPlay()
{
	Super::BeginPlay();
    PlayMusic();
}

// Called every frame
void ASoundController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

