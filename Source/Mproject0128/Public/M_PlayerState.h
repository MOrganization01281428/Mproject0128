#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "M_Character.h"
#include "M_Controller.h"

#include "M_PlayerState.generated.h"

UCLASS()
class AM_PlayerState :public APlayerState
{
	GENERATED_BODY()
public:
	AM_PlayerState();
public:
	class AM_Controller* SPController;
	
public:
	void setHealth(float value);
	void setMana(float value);
	void OnRecoverMana(float Recover);
	void OnCostMana(float Cost);
	
	bool SetIsMeditation(bool IsMeditation);
	virtual void BeginPlay() override;

private:
	float Health;
	float Mana;
	bool IsMeditation;

};