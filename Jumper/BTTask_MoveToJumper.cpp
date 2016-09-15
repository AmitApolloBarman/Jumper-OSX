// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "JumperCharacter.h"
#include "EnemyAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "BTTask_MoveToJumper.h"


void UBTTask_MoveToJumper::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	AEnemyAI *EnemyPC = Cast<AEnemyAI>(OwnerComp.GetAIOwner());
	if (EnemyPC)
		if (EnemyPC->tChar->EnemyLife > 0 && ProcessMode(EnemyPC))
			Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
		else
			Abort(OwnerComp, NodeMemory);
}

void UBTTask_MoveToJumper::Abort(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	Super::AbortTask(OwnerComp, NodeMemory);
}

void UBTTask_MoveToJumper::ProcessMode(AEnemyAI *EnemyPC, AJumperCharacter *Enemy, UBehaviorTreeComponent& OwnerComp) {
	switch (EnemyPC->tChar->Mode) {
	case EnemyMode::Attack:
	case EnemyMode::Dead:
	case EnemyMode::Flee:
	case EnemyMode::Hit:
	case EnemyMode::Idle:
	case EnemyMode::Patrol:  break;
	case EnemyMode::Pursue: break;
	case EnemyMode::Taunt: break;
	case EnemyMode::Talk: break;
	default: 
		break;
	}
}

bool UBTTask_MoveToJumper::ProcessMode(AEnemyAI *EnemyPC) {
	switch (EnemyPC->tChar->Mode) {
	case EnemyMode::Attack:break;
	case EnemyMode::Dead:break;
	case EnemyMode::Flee:break;
	case EnemyMode::Hit:break;
	case EnemyMode::Idle:break;
	case EnemyMode::Patrol: break;
	case EnemyMode::Pursue: return true;
	case EnemyMode::Taunt: break;
	case EnemyMode::Talk: break;
	default:
		break;
	}
	return false;
}