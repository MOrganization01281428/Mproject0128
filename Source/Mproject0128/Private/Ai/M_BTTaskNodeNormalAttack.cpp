// Fill out your copyright notice in the Description page of Project Settings.


#include "M_BTTaskNodeNormalAttack.h"
#include "M_EnemyAIController.h"
#include "M_EnemyCharacter.h"
#include "M_Types.h"
#include "NavigationSystem.h"
//UNavigationSystemV1* NavMesh = UNavigationSystemV1::GetCurrent(this);
//https://www.engineworld.cn/thread-6832-1-1.html


#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UM_BTTaskNodeNomalAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//如果初始化敌人参数不成功,直接返回失败
	if (!InitEnemyElement(OwnerComp)) return EBTNodeResult::Failed;
	//设置参数为了尽可能简洁，我删除了所有动画，依据动画时间参数进行的函数，统一将该参数设置为4s;
	//OwnerComp.GetBlackboardComponent()->SetValueAsFloat(WaitTime.SelectedKeyName, AttackDuration);
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(WaitTime.SelectedKeyName,4);
	return EBTNodeResult::Succeeded;
}
