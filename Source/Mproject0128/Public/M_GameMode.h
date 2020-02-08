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
	class AM_Controller* SPController;//均为重复声明，必要时删除
	class AM_Character* SPCharacter;//均为重复声明，必要时删除
	class AM_PlayerState* SPState;//均为重复声明，必要时删除

public:
		void InicialGameMode();
public:
	
public:
	virtual void BeginPlay() override;
};