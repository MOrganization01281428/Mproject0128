// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "M_BTTaskNodeBase.h"
#include "M_BTTaskNodeWonder.generated.h"
UCLASS()
class MPROJECT0128_API UM_BTTaskNodeWonder : public UM_BTTaskNodeBase
{
	GENERATED_BODY()

		//重写执行函数
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector Destination;

	//修改等待时间
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaitTime;

};
