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
        AJumperCharacter *Enemy = Cast<AJumperCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
        if (!Enemy) {
            return;
        } else if (Enemy && EnemyPC->tChar->EnemyLife>0) {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->PatrolKeyID,EnemyPC);
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID,Enemy);
        }
		if (EnemyPC->tChar->EnemyLife<=0)
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->isZombieDeadBBKeyID, false);
		uint8 EnemyMode = OwnerComp.GetBlackboardComponent()->GetValueAsEnum("EnemyModeBB");
		FString str = FString::FromInt(EnemyMode);
		EnemyPC->tChar->SetMode(EnemyMode);
		/*
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, str);
		*/
	}
}

void UBTService_CheckForPlayer::ProcessMode(AEnemyAI *EnemyPC, AJumperCharacter *Enemy, UBehaviorTreeComponent& OwnerComp) {
    switch (EnemyPC->tChar->Mode) {
        case EnemyMode::Attack:
        case EnemyMode::Dead:
        case EnemyMode::Flee:
        case EnemyMode::Hit:
        case EnemyMode::Idle:
        case EnemyMode::Patrol: OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->PatrolKeyID,EnemyPC); 
								OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID, EnemyPC);
								break;
        case EnemyMode::Pursue: OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID,Enemy); break;
        case EnemyMode::Taunt: break;
        case EnemyMode::Talk: break;
        default:
            break;
    }
}

