// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

// State Machine Mode for Enemy
UENUM(BlueprintType)
enum class EnemyMode : uint8
{
    Attack      UMETA(DisplayName="Attack"),
    Dead        UMETA(DisplayName="Dead"),
    Flee        UMETA(DisplayName="Flee"),
    Hit         UMETA(DisplayName="Hit"),
    Idle        UMETA(DisplayName="Idle"),
    Patrol      UMETA(DisplayName="Patrol"),
    Pursue      UMETA(DisplayName="Pursue"),
    Talk        UMETA(DisplayName="Talk"),
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

    // Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    // Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    // Functions
    UFUNCTION(BlueprintCallable,Category = "Enemy Mode")
    void ProcessMode(EnemyMode m);
    UFUNCTION(BlueprintCallable,Category = "Enemy Mode")
    void SetMode(EnemyMode m);
	void SetMode(uint8 m);

    UFUNCTION(BlueprintCallable,Category = "Enemy Movement")
    void MoveLeft(float Value);
    UFUNCTION(BlueprintCallable,Category = "Enemy Movement")
    void MoveRight(float Value);
    UFUNCTION(BlueprintCallable,Category = "Enemy Life")
    void DecrementLife(float x);
    // Properties
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Mode")
    EnemyMode Mode = EnemyMode::Pursue;
    float RunningTime = 0.0f;
};
