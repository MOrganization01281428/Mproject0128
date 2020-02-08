#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "M_GameMode.generated.h"

UCLASS()
class AM_GameMode :public AGameModeBase
{
	GENERATED_BODY()

public:
	AM_GameMode();

public:
	class AM_Controller* SPController;//��Ϊ�ظ���������Ҫʱɾ��
	class AM_Character* SPCharacter;//��Ϊ�ظ���������Ҫʱɾ��
	class AM_PlayerState* SPState;//��Ϊ�ظ���������Ҫʱɾ��

public:
		void InicialGameMode();
public:
	
public:
	virtual void BeginPlay() override;
};