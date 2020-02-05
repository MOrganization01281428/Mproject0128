// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "M_MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API AM_MainMenuHUD : public AHUD
{
	GENERATED_BODY()
	

	virtual void BeginPlay() override;

private:
	TSubclassOf<class UUserWidget> MainMenuWidgetClass;

};
