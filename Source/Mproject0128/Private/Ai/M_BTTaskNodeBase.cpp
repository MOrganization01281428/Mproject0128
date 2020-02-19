// Fill out your copyright notice in the Description page of Project Settings.


#include "M_BTTaskNodeBase.h"
#include "M_EnemyAIController.h"
#include "M_EnemyCharacter.h"



bool UM_BTTaskNodeBase::InitEnemyElement(UBehaviorTreeComponent& OwnerComp)
{
	//����Ѿ���ʼ����,ֱ��return,�����ظ�����
	if (SEController && SECharacter) return true;
	//���и�ֵ
	SEController = Cast<AM_EnemyAIController>(OwnerComp.GetAIOwner());
	if (SEController) {
		SECharacter = Cast<AM_EnemyCharacter>(SEController->GetPawn());
		if (SECharacter) return true;
	}
	return false;
}
