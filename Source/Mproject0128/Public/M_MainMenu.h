// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "M_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class MPROJECT0128_API UM_MainMenu : public UUserWidget
{
	GENERATED_BODY()
	

	UPROPERTY(meta = (BindWidget))
		class UButton* StartBotton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ContinueBotton;

	UPROPERTY(meta = (BindWidget))
		class UButton* SettingBotton;

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitBotton;

public:

	UFUNCTION()
		void OnClickedStart();

	UFUNCTION()
		void OnClickedContinue();

	UFUNCTION()
		void OnClickedSetting();

	UFUNCTION()
		void OnClickedQuit();
};
