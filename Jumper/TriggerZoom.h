// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "TriggerZoom.generated.h"

UCLASS()
class JUMPER_API ATriggerZoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerZoom();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    /** called when something enters the actor */
    UFUNCTION()
    void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    /** called when something leaves actor */
    UFUNCTION()
    void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    /** Toggles the camera zoom*/
    UFUNCTION()
    void ToggleCamera(float x);
	
};
