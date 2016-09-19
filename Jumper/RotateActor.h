// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "RotateActor.generated.h"
UENUM(BlueprintType)
enum class Modes : uint8
{
    Yaw 	 UMETA(DisplayName="Yaw"),
    Pitch 	 UMETA(DisplayName="Pitch"),
    Roll     UMETA(DisplayName="Roll")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JUMPER_API URotateActor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URotateActor();
    
	// Called when the game starts
	virtual void BeginPlay() override;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float RotationRate = 4000.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    Modes Mode = Modes::Yaw;
    
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
