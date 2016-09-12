// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "RotateActor.h"


// Sets default values for this component's properties
URotateActor::URotateActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateActor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotateActor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
    FRotator rot = GetOwner()->GetActorRotation();
    switch (Mode) {
        case Modes::Yaw: rot.Yaw+=RotationRate * DeltaTime;break;
        case Modes::Pitch: rot.Pitch+=RotationRate * DeltaTime;break;
        case Modes::Roll: rot.Roll+=RotationRate * DeltaTime;break;
    }
    
    GetOwner()->SetActorRotation(rot);
}

