// Fill out your copyright notice in the Description page of Project Settings.

#include "Jumper.h"
#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}
// Called when the game starts or when spawned
void AFloatingActor::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    if (!isVertical && !isHorizontal) {
        FVector Offset;
        Offset.X = (FMath::Sin((RunningTime + DeltaTime) * Period.X) - FMath::Sin(RunningTime * Period.X)) * Scale.X;
        Offset.Y = (FMath::Sin((RunningTime + DeltaTime) * Period.Y) - FMath::Sin(RunningTime * Period.Y)) * Scale.Y;
        Offset.Z = (FMath::Sin((RunningTime + DeltaTime) * Period.Z) - FMath::Sin(RunningTime * Period.Z)) * Scale.Z;
        RunningTime += DeltaTime;
    
        AddActorLocalOffset(Offset);
    
        AddActorLocalRotation(Rotation * DeltaTime);
    } else {
     FVector NewLocation = GetActorLocation();
     float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
     if (isHorizontal)
         NewLocation.Y += DeltaHeight * Speed;       //Scale our distance by a factor of 20
     if (isVertical)
         NewLocation.Z += DeltaHeight * Speed;       //Scale our height by a factor of 20
     RunningTime += DeltaTime;
	 SetActorLocation(NewLocation, collide);
    }
}

