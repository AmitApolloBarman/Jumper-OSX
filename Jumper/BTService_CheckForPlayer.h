// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "BehaviorTree/BTService.h"
#include "BTService_CheckForPlayer.generated.h"

UCLASS()
class JUMPER_API UBTService_CheckForPlayer : public UBTService
{
	GENERATED_BODY()
	
	
public:
    UBTService_CheckForPlayer();
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* nodeMemory, float DeltaSeconds) override;
	
};
