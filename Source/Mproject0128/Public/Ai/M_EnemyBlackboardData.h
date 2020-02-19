// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "M_EnemyBlackboardData.generated.h"


UCLASS()
class MPROJECT0128_API UM_EnemyBlackboardData : public UBlackboardData
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Control")
		void PostLoad();

};
