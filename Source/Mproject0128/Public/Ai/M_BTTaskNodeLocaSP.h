// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "M_BTTaskNodeBase.h"
#include "M_BTTaskNodeLocaSP.generated.h"
UCLASS()
class MPROJECT0128_API UM_BTTaskNodeLocaSP : public UM_BTTaskNodeBase
{
	GENERATED_BODY()

		//ÖØÐ´Ö´ÐÐº¯Êý
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector Destination;

};
