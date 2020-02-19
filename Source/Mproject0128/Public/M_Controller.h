#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//��������
#include "M_Character.h"
#include "M_PlayerState.h"

#include "M_Controller.generated.h"

//���յ�˵��������ʵ�ֵĲ������ݣ��������������
//���յء�UIί��ϵ��

UCLASS()
class AM_Controller :public APlayerController
{
	GENERATED_BODY()

public:
	AM_Controller();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;



public:
	//���Click�¼�
	void LeftClickStart();
	void LeftClickStop();
	void RightClickStart();
	void RightClickStop();
	//�������¹����¼�
	void RollUpEvent();
	void RollDownEvent();
	//ESC�¼�
	void EscEvent();

public:
	//����ָ��
	class AM_Character* SPCharacter;
	class AM_PlayerState* SPState;

	void PlayerDead();


};