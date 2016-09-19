// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class JUMPER_API AFloatingActor : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    AFloatingActor();
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    float Speed=20;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    bool isVertical;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    bool isHorizontal;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    FVector Period = { 1.2f, 0.8f, 1.0f };
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    FVector Scale = { 10.0f, 10.0f, 20.0f };
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Collision")
    bool collide = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    FRotator Rotation = { 0.0f, 0.0f, 3.0f };

    
    float RunningTime = 0.0f;
};
