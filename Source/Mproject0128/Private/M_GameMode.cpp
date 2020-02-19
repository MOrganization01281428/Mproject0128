
#include "M_GameMode.h"
#include "M_Character.h"
#include "M_Controller.h"
#include "M_PlayerState.h"

//#include "M_DataHandle.h"
#include "..\..\Public\Data\M_DataHandle.h"
#include "M_GameInstance.h"
#include "M_SaveGame.h"

#include "Kismet/GameplayStatics.h"

#include "M_Character.h"
#include "M_Controller.h"
#include "M_PlayerState.h"


#include "M_DataHandle.h"
#include "M_Instance.h"
#include "M_Save.h"

#include "Kismet/GameplayStatics.h"
//GameMode˵����Ŀǰ�����޸Ĵ浵���֣�����֮��û��ʵ���κζ�����

AM_GameMode::AM_GameMode()
{
	//��������tick����
	PrimaryActorTick.bCanEverTick = true;
	PlayerControllerClass = AM_Controller::StaticClass();
	PlayerStateClass = AM_PlayerState::StaticClass();
	DefaultPawnClass = AM_Character::StaticClass();
	//��ʼ���ò���Ҫ���ش浵
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
