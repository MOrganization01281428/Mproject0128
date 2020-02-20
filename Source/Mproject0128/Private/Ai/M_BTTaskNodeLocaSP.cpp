// Fill out your copyright notice in the Description page of Project Settings.


#include "M_BTTaskNodeLocaSP.h"
#include "M_EnemyAIController.h"
#include "M_EnemyCharacter.h"
#include "M_Types.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"



EBTNodeResult::Type UM_BTTaskNodeLocaSP::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//如果初始化敌人参数不成功,直接返回失败
	if (!InitEnemyElement(OwnerComp)) return EBTNodeResult::Failed;

	//范围是20以内
	const float ChaseRadius = 20.f;
	//获取玩家到敌人之间的单位向量
	FVector SPToSE = SEController->GetPlayerLocation() - SECharacter->GetActorLocation();
	SPToSE.Normalize();
	//探索起点是玩家位置减去与敌人之间距离的一点点
	const FVector ChaseOrigin = SEController->GetPlayerLocation() - 100.f * SPToSE;
	//保存随机的位置
	FVector DesLoc(0.f);
	//使用导航系统获取随机点
	UNavigationSystemV1::K2_GetRandomReachablePointInRadius(SEController, ChaseOrigin, DesLoc, ChaseRadius);
	//修改目的地
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(Destination.SelectedKeyName, DesLoc);
	//返回成功
	return EBTNodeResult::Succeeded;
	
}
