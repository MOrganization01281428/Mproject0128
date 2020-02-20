// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "M_EnemyCharacter.h"
#include "M_Character.h"
#include "M_EnemyAIController.generated.h"

UCLASS()
class MPROJECT0128_API AM_EnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AM_EnemyAIController();

	virtual void OnPossess(APawn* InPawn) override;

public:
	class AM_EnemyCharacter* SECharacter;
	class AM_Character* SPCharacter;
	class UBlackboardComponent* BlackboardComp;
	class UBehaviorTreeComponent* BehaviorComp;
public:
	void EnemyDead();
	//��Ϊ�����
	bool IsPlayerDead();
	void OnSeePlayer();
	void LoosePlayer();
	UObject* GetPlayerPawn();
	//��ȡ��ҵ�λ��
	FVector GetPlayerLocation() const;

public:
	bool IsLockPlayer;
	//��������ҵľ�������,����8��,ÿ�������һ��
	TArray<float> EPDisList;
	//ʱ��ί�о��
	FTimerHandle EPDisHandle;
};
