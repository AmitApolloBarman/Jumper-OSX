// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "EnemyAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"

AEnemyAI::AEnemyAI() {
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
    BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
    isDead = false;
}

// Called every frame
void AEnemyAI::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    if (tChar)
        if (tChar->EnemyLife<=0) {
            isDead = true;
            BehaviorComp->StopTree();
        }
    
}

void AEnemyAI::Possess(APawn *InPawn) {
    Super::Possess(InPawn);
    AEnemyCharacter *Char = Cast<AEnemyCharacter>(InPawn);
 
    if (Char && Char->ZombieBehavior) {
        BlackboardComp->InitializeBlackboard(*Char->ZombieBehavior->BlackboardAsset);
        EnemyKeyID = BlackboardComp->GetKeyID("Target");
        PatrolKeyID = BlackboardComp->GetKeyID("PatrolTarget");
		EnemyModeBBKeyID = BlackboardComp->GetKeyID("EnemyModeBB");
		isZombieDeadBBKeyID = BlackboardComp->GetKeyID("isZombieDeadBB"); 
		tChar = Char;
        BehaviorComp->StartTree(*Char->ZombieBehavior);
    }
}
