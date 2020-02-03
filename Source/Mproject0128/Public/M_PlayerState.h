#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "M_PlayerState.generated.h"

UCLASS()
class AM_PlayerState :public APlayerState
{
	GENERATED_BODY()
public:
	AM_PlayerState();
	
public:
	void setHealth(float value);
	void setMana(float value);

private:
	float Health;
	float Mana;

};