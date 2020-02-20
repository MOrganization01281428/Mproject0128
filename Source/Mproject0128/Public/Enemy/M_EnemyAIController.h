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
	//行为树相关
	bool IsPlayerDead();
	void OnSeePlayer();
	void LoosePlayer();
	UObject* GetPlayerPawn();
	//获取玩家的位置
	FVector GetPlayerLocation() const;

public:
	bool IsLockPlayer;
	//保存与玩家的距离序列,保存8个,每半秒更新一次
	TArray<float> EPDisList;
	//时间委托句柄
	FTimerHandle EPDisHandle;
};
