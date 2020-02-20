// Fill out your copyright notice in the Description page of Project Settings.


#include "M_BTTaskNodeWonder.h"
#include "M_EnemyAIController.h"
#include "M_EnemyCharacter.h"
#include "M_Types.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"



EBTNodeResult::Type UM_BTTaskNodeWonder::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//�����ʼ�����˲������ɹ�,ֱ�ӷ���ʧ��
	if (!InitEnemyElement(OwnerComp)) return EBTNodeResult::Failed;

	//��ﷶΧ��1000
	const float WanderRadius = 1000.f;
	//���������Լ���λ��
	const FVector WanderOrigin = SECharacter->GetActorLocation();
	//���������λ��
	FVector DesLoc(0.f);
	//ʹ�õ���ϵͳ��ȡ�����
	UNavigationSystemV1::K2_GetRandomReachablePointInRadius(SEController, WanderOrigin, DesLoc, WanderRadius);
	//������С��500ʱ,�����ҵ�
	while (FVector::Distance(WanderOrigin, DesLoc) < 500.f)
	{
		//ʹ�õ���ϵͳ���»�ȡ�����
		UNavigationSystemV1::K2_GetRandomReachablePointInRadius(SEController, WanderOrigin, DesLoc, WanderRadius);
	}
	//�޸�Ŀ�ĵ�
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(Destination.SelectedKeyName, DesLoc);
	//��ȡͣ��ʱ��
	float TotalWaitTime = SECharacter->GetIdleWaitTime();
	//�޸ĵȴ�ʱ��
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(WaitTime.SelectedKeyName, TotalWaitTime);
	//���سɹ�
	return EBTNodeResult::Succeeded;
	
}
