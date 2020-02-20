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
	//�����ʼ�����˲������ɹ�,ֱ�ӷ���ʧ��
	if (!InitEnemyElement(OwnerComp)) return EBTNodeResult::Failed;
	//���ò���Ϊ�˾����ܼ�࣬��ɾ�������ж��������ݶ���ʱ��������еĺ�����ͳһ���ò�������Ϊ4s;
	//OwnerComp.GetBlackboardComponent()->SetValueAsFloat(WaitTime.SelectedKeyName, AttackDuration);
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(WaitTime.SelectedKeyName,4);
	return EBTNodeResult::Succeeded;
}
