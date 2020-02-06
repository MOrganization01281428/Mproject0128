#include "M_PlayerState.h"

#include "TimerManager.h"
#include "Engine/Engine.h"

#include "Kismet/GameplayStatics.h"
#include "M_Controller.h"

AM_PlayerState::AM_PlayerState()
{
	Health = 100.0f;
	Mana = 100.0f;
}

void AM_PlayerState::setHealth(float value)
{
	Health = value;
}

void AM_PlayerState::setMana(float value)
{
	Health = value;
}

void AM_PlayerState::OnRecoverMana(float Recover)
{
	while (IsMeditation)
	{
		FPlatformProcess::Sleep(100);
		Mana = Mana + Recover;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, FString::SanitizeFloat(Mana));
	}
}

void AM_PlayerState::OnCostMana(float Cost)
{
	FPlatformProcess::Sleep(Cost);
	Mana = Mana + Cost;
}

bool AM_PlayerState::SetIsMeditation(bool IsMeditation)
{
	return  IsMeditation;
}

void AM_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	//如果控制器指针为空,添加引用
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}
