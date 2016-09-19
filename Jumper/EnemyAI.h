// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "AIController.h"
#include "EnemyCharacter.h"
#include "EnemyAI.generated.h"
/**
 * 
 */
UCLASS()
class JUMPER_API AEnemyAI : public AAIController {
	GENERATED_BODY()
	
    UPROPERTY(transient)
    class UBlackboardComponent *BlackboardComp;
    
    UPROPERTY(transient)
    class UBehaviorTreeComponent *BehaviorComp;
    
public:
    virtual void Tick( float DeltaSeconds ) override;
    AEnemyAI();
    AEnemyCharacter *tChar;
    virtual void Possess(APawn *InPawn) override;
	
    uint8 EnemyKeyID;
    uint8 PatrolKeyID;
	uint8 EnemyModeBBKeyID;
	uint8 isZombieDeadBBKeyID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveEnemy")
    bool isDead = false;
};
