// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "LightSwitchCodeOnly.generated.h"

UCLASS()
class JUMPER_API ALightSwitchCodeOnly : public AActor
{
	GENERATED_BODY()
	
public:
    /** point light component */
    UPROPERTY(VisibleAnywhere, Category = "Switch Components")
    class UPointLightComponent* PointLight1;
    
    /** sphere component */
    UPROPERTY(VisibleAnywhere, Category = "Switch Components")
    class USphereComponent* Sphere1;
    
    /** called when something enters the sphere component */
    UFUNCTION()
    void OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    /** called when something leaves the sphere component */
    UFUNCTION()
    void OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void ToggleLight();
	// Sets default values for this actor's properties
	ALightSwitchCodeOnly();
    
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    /** the desired intensity for the light */
    UPROPERTY(VisibleAnywhere, Category="Switch Variables")
    float DesiredIntensity;
	
};
