// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"
UENUM(BlueprintType)
enum class EnemyMode : uint8
{
    Pursue      UMETA(DisplayName="Pursue"),
    Patrol      UMETA(DisplayName="Patrol"),
    Attack      UMETA(DisplayName="Attack"),
    Flee        UMETA(DisplayName="Fleeing"),
    Talk        UMETA(DisplayName="Talk"),
    Dead        UMETA(DisplayName="Dead"),
    Taunt       UMETA(DisplayName="Taunt")
};

UCLASS()
class JUMPER_API AEnemyCharacter : public ACharacter {
	GENERATED_BODY()

public:
    const float LIFE_INC = 0.01;
	// Sets default values for this character's properties
	AEnemyCharacter();
    UPROPERTY(EditAnywhere, Category = Behavior)
    class UBehaviorTree *ZombieBehavior;

    UFUNCTION(BlueprintCallable,Category = "Enemy Mode")
    void ProcessMode(EnemyMode m);
    UFUNCTION(BlueprintCallable,Category = "Enemy Mode")
    void SetMode(EnemyMode m);
    // Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    // Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Properties")
    float hit = 0.05;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Properties")
    float MAX_LIFE = 15.0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Properties")
    float EnemyLife=15;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Properties")
    float Speed=50;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Properties")
    float Radius=25;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Properties")
    float GlobalAnimationRate=2.5f;
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Mode")
    EnemyMode Mode = EnemyMode::Pursue;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating Movement")
    FRotator Rotation = { 0.0f, 0.0f, 3.0f };
	float RunningTime = 0.0f;
    void MoveChar(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable,Category = "Enemy Life")
    void DecrementLife(float x);
};
