#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "M_Save.h"
#include "M_GameMode.generated.h"

UCLASS()
class AM_GameMode :public AGameModeBase
{
	GENERATED_BODY()

public:
	AM_GameMode();
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

public:

	class AM_Controller* SPController;
	class AM_Character* SPCharacter;
	class AM_PlayerState* SPState;

public:
	//保存游戏
	void SaveGame();
	//存档加载
	void LoadGame();
	//是否需要加载存档
	bool IsNeedLoadGame;
	//游戏存档指针
	class UM_Save* GameRecord;

};