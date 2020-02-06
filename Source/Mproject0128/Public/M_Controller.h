#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//¹ØÁª°üº¬
#include "M_Character.h"
#include "M_PlayerState.h"

#include "M_Controller.generated.h"

UCLASS()
class AM_Controller :public APlayerController
{
	GENERATED_BODY()

public:
	AM_Controller();

public:
	class AM_Character* SPCharacter;
	class AM_PlayerState* SPState;

	void PlayerDead();

public:
	virtual void BeginPlay() override;
	/*
	public:
	TSubClass<m_PLAYERSTATE> PLAYER
	*/

};