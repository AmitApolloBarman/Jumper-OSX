// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_MoveToJumper.generated.h"

/**
 * 
 */
UCLASS()
class JUMPER_API UBTTask_MoveToJumper : public UBTTask_MoveTo
{
	GENERATED_BODY()
	bool ProcessMode(AEnemyAI *EnemyPC);
	void ProcessMode(AEnemyAI *EnemyPC, AJumperCharacter *Enemy, UBehaviorTreeComponent& OwnerComp);
	void Abort(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
