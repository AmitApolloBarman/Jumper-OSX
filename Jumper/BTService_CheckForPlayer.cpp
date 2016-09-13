// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "EnemyAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "JumperCharacter.h"
#include "BTService_CheckForPlayer.h"


UBTService_CheckForPlayer::UBTService_CheckForPlayer(){
    bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    AEnemyAI *EnemyPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());
    if ( EnemyPC) {
        if (EnemyPC->tChar->EnemyLife<=0)
            OwnerComp.StopTree();
        AJumperCharacter *Enemy = Cast<AJumperCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
        if (Enemy && EnemyPC->tChar->EnemyLife>0)
            ProcessMode(EnemyPC,Enemy,OwnerComp);
    }
}

void UBTService_CheckForPlayer::ProcessMode(AEnemyAI *EnemyPC, AJumperCharacter *Enemy, UBehaviorTreeComponent& OwnerComp) {
    switch (EnemyPC->tChar->Mode) {
        case EnemyMode::Pursue: OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID,Enemy); break;
        case EnemyMode::Attack:
        case EnemyMode::Dead:
        case EnemyMode::Patrol:
        case EnemyMode::Flee:
        case EnemyMode::Taunt:
        case EnemyMode::Talk:
        default: OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID,EnemyPC);
            break;
    }
}

