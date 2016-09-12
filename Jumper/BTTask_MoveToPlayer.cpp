// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "BTTask_MoveToPlayer.h"
#include "EnemyAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "JumperCharacter.h"


EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
  
    AEnemyAI *CharPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());
    AJumperCharacter *Enemy = Cast<AJumperCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));
    
    if (Enemy && CharPC->tChar) {
        if (CharPC->tChar->EnemyLife>0 && CharPC->tChar->Mode==EnemyMode::Pursue) {
                CharPC->MoveToActor(Enemy, 90.f,true,true,false,0,true);
            }
        return EBTNodeResult::Succeeded;
    } else {
        return EBTNodeResult::Failed;
    }
    
    return EBTNodeResult::Failed;
    
}