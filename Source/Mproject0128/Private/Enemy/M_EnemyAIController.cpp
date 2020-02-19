// Fill out your copyright notice in the Description page of Project Settings.


#include "M_EnemyAIController.h"
#include "UObject/Object.h"

void AM_EnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AM_EnemyAIController::EnemyDead()
{
}

void AM_EnemyAIController::IsPlayerDead()
{
}

void AM_EnemyAIController::OnSeePlayer()
{
}

void AM_EnemyAIController::LoosePlayer()
{
}



UObject* AM_EnemyAIController::GetPlayerPawn()
{
	return SPCharacter;
}

