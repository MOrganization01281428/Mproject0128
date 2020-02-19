// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "M_Save.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API UM_Save : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, Category = "MSave")
		FVector PlayerLocation;

	UPROPERTY(VisibleAnywhere, Category = "MSave")
		float PlayerHP;

	UPROPERTY(VisibleAnywhere, Category = "MSave")
		float PlayerMP;

	UPROPERTY(VisibleAnywhere, Category = "MSave")
		TArray<FVector> EnemyLoaction;

	UPROPERTY(VisibleAnywhere, Category = "MSave")
		TArray<float> EnemyHP;

};
