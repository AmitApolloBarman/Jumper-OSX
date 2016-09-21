// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "MyActorController.h"


// Sets default values
AMyActorController::AMyActorController()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void AMyActorController::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AMyActorController::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
    
}
