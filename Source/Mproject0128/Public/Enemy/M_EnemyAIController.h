// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "M_EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API AM_EnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AM_EnemyAIController();
	//Æô¶¯Pawn¿ØÖÆ
	virtual void Possess(APawn* InPawn) override;

	virtual void UnPossess() override;

	virtual void Tick(float DeltaTime) override;
	
};
