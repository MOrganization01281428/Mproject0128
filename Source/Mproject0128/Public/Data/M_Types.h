// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "SBorder.h"
#include "SImage.h"
#include "STextBlock.h"
#include "SlateBasics.h"

UENUM(BlueprintType)
enum  class EEnemyAIState : uint8
{
	ES_Patrol    UMETA(DisplayName = "Patrol"),
	ES_Escape    UMETA(DisplayName = "Escape"),
	ES_Attack    UMETA(DisplayName = "Attack"),
	ES_Dead      UMETA(DisplayName = "Dead")
};

//µÐÈË¹¥»÷×´Ì¬
UENUM(BlueprintType)
enum class EEnemyAttackType : uint8
{
	EA_Normal   UMETA(DisplayName = "Normal"),
};

