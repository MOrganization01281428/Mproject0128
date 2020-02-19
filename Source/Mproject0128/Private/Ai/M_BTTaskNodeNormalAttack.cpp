// Fill out your copyright notice in the Description page of Project Settings.


#include "M_BTTaskNodeNormalAttack.h"
#include "M_EnemyAIController.h"
#include "M_EnemyCharacter.h"
#include "NavigationSystem.h"
//UNavigationSystemV1* NavMesh = UNavigationSystemV1::GetCurrent(this);
//https://www.engineworld.cn/thread-6832-1-1.html


#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UM_BTTaskNodeNomalAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{/*
	//如果初始化敌人参数不成功,直接返回失败
	if (!InitEnemyElement(OwnerComp)) return EBTNodeResult::Failed;
	//设置参数
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(WaitTime.SelectedKeyName, AttackDuration);
*/
	return EBTNodeResult::Succeeded;
}
