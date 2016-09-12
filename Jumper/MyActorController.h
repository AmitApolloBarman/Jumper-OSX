// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActorController.generated.h"

UCLASS()
class JUMPER_API AMyActorController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
