// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "M_Instance.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API UM_Instance : public UGameInstance
{
	GENERATED_BODY()
		//virtual void Init() override;

		UPROPERTY(VisibleAnywhere, Category = "MInstance")
		FString GameName;
};
