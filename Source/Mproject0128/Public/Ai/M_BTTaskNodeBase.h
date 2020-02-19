// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "M_BTTaskNodeBase.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API UM_BTTaskNodeBase : public UBTTaskNode
{
	GENERATED_BODY()
	
public:

	bool InitEnemyElement(UBehaviorTreeComponent& OwnerComp);

	class AM_EnemyAIController* SEController;

	class AM_EnemyCharacter* SECharacter;
};
