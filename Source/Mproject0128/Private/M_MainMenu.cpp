// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Button.h"
#include "M_MainMenu.h"

bool UM_MainMenu::Initialize() 
{
	Super::Initialize();


	if (StartBotton != nullptr) {
		StartBotton->OnClicked.AddDynamic(this, &UM_MainMenu::OnClickedStart);
	}

	if (ContinueBotton != nullptr) {
		ContinueBotton->OnClicked.AddDynamic(this, &UM_MainMenu::OnClickedContinue);
	}

	if (SettingBotton != nullptr) {
		SettingBotton->OnClicked.AddDynamic(this, &UM_MainMenu::OnClickedSetting);
	}

	if (QuitBotton != nullptr) {
		QuitBotton->OnClicked.AddDynamic(this, &UM_MainMenu::OnClickedQuit);
	}

	return true;
}

void UM_MainMenu::OnClickedStart()
{
	FString NewMap = FString::Printf(TEXT("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap"));

	GetWorld()->ServerTravel(NewMap);

}

void UM_MainMenu::OnClickedContinue()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClicked Continue"));

}

void UM_MainMenu::OnClickedSetting()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClicked Setting"));
}

void UM_MainMenu::OnClickedQuit()
{
	PC->ConsoleCommand(TEXT("quit"));
}
