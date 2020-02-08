#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "M_SaveGame.h"

#include "M_PlayerState.generated.h"

//DECLARE_LOG_CATEGORY_EXTERN(YourLog, Log, All);
UCLASS()
class AM_PlayerState :public APlayerState
{
	GENERATED_BODY()
public: 
	AM_PlayerState();
public:
	class AM_Controller* SPController;//�Ѿ���Character����������ͷ�����ˡ�

public:
	class UM_SaveGame* SaveInstance;

	
public:
	void setHealth(float value);
	float getHealth();
	void setMana(float value);
	float getMana();
	void OnRecoverMana(float Recover);
	void OnCostMana(float Cost);
	bool SetIsMeditation(bool IsMeditation);

	//�浵ϵͳ
	UFUNCTION(BlueprintCallable)
		void SaveGame(FString SlotName);
	UFUNCTION(BlueprintCallable)
		void LoadGame(FString SlotName);

	virtual void BeginPlay() override;

private:
	float Health;
	float Mana;
	bool IsMeditation;

};