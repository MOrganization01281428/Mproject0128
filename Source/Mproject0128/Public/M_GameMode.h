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
	//������Ϸ
	void SaveGame();
	//�浵����
	void LoadGame();
	//�Ƿ���Ҫ���ش浵
	bool IsNeedLoadGame;
	//��Ϸ�浵ָ��
	class UM_Save* GameRecord;

};