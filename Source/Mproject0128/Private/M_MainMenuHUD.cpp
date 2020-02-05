// Fill out your copyright notice in the Description page of Project Settings.

#include "M_MainMenuHUD.h"
#include "M_MainMenu.h"
#include "UObject/ConstructorHelpers.h"

AM_MainMenuHUD::AM_MainMenuHUD(const FObjectInitializer& Initailizer)
	: Super(Initailizer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetBP(TEXT("/Game/ThirdPersonCPP/UI/MainMenu")); // 找到蓝图类
	if (MainMenuWidgetBP.Succeeded())
	{
		MainMenuWidgetClass = MainMenuWidgetBP.Class; // 得到class
	}
}

void AM_MainMenuHUD::BeginPlay()
{
	if (MainMenuWidgetClass != nullptr)
	{
		UM_MainMenu* Widget = CreateWidget<UM_MainMenu>(GetWorld()->GetGameInstance(), MainMenuWidgetClass);
		if (Widget != nullptr)
		{
			Widget->AddToViewport();
		}
	}
}