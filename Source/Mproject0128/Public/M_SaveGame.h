// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "M_SaveGame.generated.h"

/**
 * 
 */
//存储数据结构

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere)
		float PlayerHealth = 0.f;
		UPROPERTY(EditAnywhere)
		float PlayerMana = 0.f;

};

UCLASS()
class MPROJECT0128_API UM_SaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		FSPlayerInfo SPlayerStructInfo;


	UPROPERTY(VisibleAnywhere, Category = "Magic")
		float PlayerMana;
	UPROPERTY(VisibleAnywhere, Category = "Magic")
		float PlayerHP;
    /*Slate参考
	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		FVector PlayerLocation;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		float PlayerHP;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		float PlayerHunger;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<int32> InputIndex;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<int32> InputNum;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<int32> NormalIndex;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<int32> NormalNum;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<int32> ShortcutIndex;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<int32> ShortcutNum;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<FVector> EnemyLoaction;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<float> EnemyHP;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<FVector> ResourceRock;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<FVector> ResourceTree;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<FVector> PickupStone;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		TArray<FVector> PickupWood;
	*/
};
