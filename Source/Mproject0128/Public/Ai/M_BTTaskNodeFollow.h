// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "M_BTTaskNodeBase.h"
#include "BehaviorTree/Tasks/BTTask_GameplayTaskBase.h"
#include "M_BTTaskNodeFollow.generated.h"


UCLASS()
class MPROJECT0128_API UM_BTTaskNodeFollow : public UM_BTTaskNodeBase
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Destination;


};
