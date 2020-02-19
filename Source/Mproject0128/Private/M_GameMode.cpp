#include "M_GameMode.h"

#include "M_Character.h"
#include "M_Controller.h"
#include "M_PlayerState.h"


#include "M_DataHandle.h"
#include "M_Instance.h"
#include "M_Save.h"

#include "Kismet/GameplayStatics.h"
//GameMode说明，目前正在修改存档部分，除此之外没有实现任何东西。

AM_GameMode::AM_GameMode()
{
	//允许开启tick函数
	PrimaryActorTick.bCanEverTick = true;
	PlayerControllerClass = AM_Controller::StaticClass();
	PlayerStateClass = AM_PlayerState::StaticClass();
	DefaultPawnClass = AM_Character::StaticClass();
	//开始设置不需要加载存档
	IsNeedLoadGame = false;

}

void AM_GameMode::Tick(float DeltaSeconds)
{
}

void AM_GameMode::BeginPlay()
{
}

void AM_GameMode::SaveGame()
{
}

void AM_GameMode::LoadGame()
{
}
