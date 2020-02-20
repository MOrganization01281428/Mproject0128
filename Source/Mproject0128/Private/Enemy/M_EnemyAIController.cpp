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

	//˳��������ʵ����һ�½�ɫ
	SECharacter = Cast<AM_EnemyCharacter>(InPawn);

	//��ȡ��Ϊ����Դ
	UBehaviorTree* StaticBehaviorTreeObject = LoadObject<UBehaviorTree>(NULL, TEXT("BehaviorTree'/Game/BluePrint/Enemy/M_BehaviorTree.M_BehaviorTree'"));

	UBehaviorTree* BehaviorTreeObject = DuplicateObject<UBehaviorTree>(StaticBehaviorTreeObject, NULL);

	//�����Դ������,ֱ�ӷ���
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

		// ����Ԥ״̬ΪѲ��
		BlackboardComp->SetValueAsEnum("EnemyState", (uint8)EEnemyAIState::ES_Patrol);
	}

}

void AM_EnemyAIController::EnemyDead()
{
	//ֹͣ��Ϊ��
	if (BehaviorComp) BehaviorComp->StopTree(EBTStopMode::Safe);

	//��ʱ����,ע��ʱ�亯��
	if (EPDisHandle.IsValid()) GetWorld()->GetTimerManager().ClearTimer(EPDisHandle);
}

bool AM_EnemyAIController::IsPlayerDead()
{
	if (SPCharacter) return SPCharacter->IsDead();
	return false;
}

void AM_EnemyAIController::OnSeePlayer()
{
	//����Ѿ���������һ�������Ѿ�����,����ִ������ĺ���
	if (IsLockPlayer || IsPlayerDead()) return;

	//�������������
	IsLockPlayer = true;
	//�޸�Ԥ״̬Ϊ׷��
	BlackboardComp->SetValueAsEnum("EnemyState", (uint8)EEnemyAIState::ES_Chase);

}

void AM_EnemyAIController::LoosePlayer()
{
	//���ö�ʧ��ҵ�����
	IsLockPlayer = false;
}

UObject* AM_EnemyAIController::GetPlayerPawn()
{
	return SPCharacter;
}

FVector AM_EnemyAIController::GetPlayerLocation() const
{
	//������ָ�����,�������λ��
	if (SPCharacter) return SPCharacter->GetActorLocation();
	return FVector::ZeroVector;
}

