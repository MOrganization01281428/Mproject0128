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

	virtual void BeginPlay() override;

public:
	class AM_Controller* SPController;
	
public:

	void setHealth(float value);
	void setMana(float value);

	void AcceptDamage(int DamageVal);
	bool IsPlayerDead();
	void OnRecoverMana(float Recover);
	void OnCostMana(float Cost);

	//�浵ϵͳ
	UFUNCTION(BlueprintCallable)
		void SaveState(float& HP,float& MP);
	UFUNCTION(BlueprintCallable)
		void LoadState(float HP, float MP);

public:
	float Health;
	float Mana;
	bool IsDead;

};