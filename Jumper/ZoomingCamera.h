// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "ZoomingCamera.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JUMPER_API UZoomingCamera : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UZoomingCamera();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

    void OnPickup();
    UPROPERTY (BlueprintAssignable , Category="Collision" )
    FComponentBeginOverlapSignature OnComponentBeginOverlap;
    
    UPROPERTY (BlueprintAssignable , Category="Collision" )
    FComponentEndOverlapSignature OnComponentEndOverlap;

};
