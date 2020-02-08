// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "M_EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API AM_EnemyController : public AAIController
{
	GENERATED_BODY()
public:
    AM_EnemyController();

    virtual void Possess(APawn* InPawn) override;

};
