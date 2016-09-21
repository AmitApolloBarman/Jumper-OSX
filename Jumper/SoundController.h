// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "SoundController.generated.h"

UCLASS()
class JUMPER_API ASoundController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // Play music from properties
    void PlayMusic();

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    float Speed=20;
    /** sound */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    USoundBase* Sound;
    
    /** audio component for various sounds */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    UAudioComponent* SoundComponent;
private:
	
};
