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
public:
	void EnemyDead();
	void IsPlayerDead();
	void OnSeePlayer();
	void LoosePlayer();
	UObject* GetPlayerPawn();

public:
	bool IsLockPlayer;

};
