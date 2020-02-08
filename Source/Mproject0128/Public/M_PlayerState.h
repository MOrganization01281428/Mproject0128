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
<<<<<<< Updated upstream
=======
	float getMana();

	void OnRecoverMana(float Recover);
	void OnCostMana(float Cost);


	//�浵ϵͳ
	UFUNCTION(BlueprintCallable)
		void SaveGame(FString SlotName);
	UFUNCTION(BlueprintCallable)
		void LoadGame(FString SlotName);

	virtual void BeginPlay() override;
>>>>>>> Stashed changes

private:
	float Health;
	float Mana;

};