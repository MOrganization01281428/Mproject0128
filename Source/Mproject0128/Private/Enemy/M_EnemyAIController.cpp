// Fill out your copyright notice in the Description page of Project Settings.


#include "M_EnemyAIController.h"
#include "UObject/Object.h"
#include "M_Character.h"
#include "M_EnemyCharacter.h"
#include "M_EnemyBlackboardData.h"
#include "M_Types.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


AM_EnemyAIController::AM_EnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AM_EnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//顺便在这里实例化一下角色
	SECharacter = Cast<AM_EnemyCharacter>(InPawn);

	//获取行为树资源
	UBehaviorTree* StaticBehaviorTreeObject = LoadObject<UBehaviorTree>(NULL, TEXT("BehaviorTree'/Game/BluePrint/Enemy/M_BehaviorTree.M_BehaviorTree'"));

	UBehaviorTree* BehaviorTreeObject = DuplicateObject<UBehaviorTree>(StaticBehaviorTreeObject, NULL);

	//如果资源不存在,直接返回
	if (!BehaviorTreeObject) return;

	BehaviorTreeObject->BlackboardAsset = DuplicateObject<UM_EnemyBlackboardData>((UM_EnemyBlackboardData*)StaticBehaviorTreeObject->BlackboardAsset, NULL);



	BlackboardComp = Blackboard;

	bool IsSuccess = true;

	if (BehaviorTreeObject->BlackboardAsset && (Blackboard == nullptr || Blackboard->IsCompatibleWith(BehaviorTreeObject->BlackboardAsset) == false))
	{
		IsSuccess = UseBlackboard(BehaviorTreeObject->BlackboardAsset, BlackboardComp);
	}

	if (IsSuccess)
	{
		BehaviorComp = Cast<UBehaviorTreeComponent>(BrainComponent);
		if (!BehaviorComp)
		{
			BehaviorComp = NewObject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
			BehaviorComp->RegisterComponent();
		}
		BrainComponent = BehaviorComp;
		check(BehaviorComp != NULL);

		BehaviorComp->StartTree(*BehaviorTreeObject, EBTExecutionMode::Looped);

		// 设置预状态为巡逻
		BlackboardComp->SetValueAsEnum("EnemyState", (uint8)EEnemyAIState::ES_Patrol);
	}

}

void AM_EnemyAIController::EnemyDead()
{
	//停止行为树
	if (BehaviorComp) BehaviorComp->StopTree(EBTStopMode::Safe);

	//临时代码,注销时间函数
	if (EPDisHandle.IsValid()) GetWorld()->GetTimerManager().ClearTimer(EPDisHandle);
}

bool AM_EnemyAIController::IsPlayerDead()
{
	if (SPCharacter) return SPCharacter->IsDead();
	return false;
}

void AM_EnemyAIController::OnSeePlayer()
{
	//如果已经锁定了玩家或者玩家已经死了,不再执行下面的函数
	if (IsLockPlayer || IsPlayerDead()) return;

	//设置锁定了玩家
	IsLockPlayer = true;
	//修改预状态为追逐
	BlackboardComp->SetValueAsEnum("EnemyState", (uint8)EEnemyAIState::ES_Chase);

}

void AM_EnemyAIController::LoosePlayer()
{
	//设置丢失玩家的锁定
	IsLockPlayer = false;
}

UObject* AM_EnemyAIController::GetPlayerPawn()
{
	return SPCharacter;
}

FVector AM_EnemyAIController::GetPlayerLocation() const
{
	//如果玩家指针存在,返回玩家位置
	if (SPCharacter) return SPCharacter->GetActorLocation();
	return FVector::ZeroVector;
}

