#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "M_Controller.generated.h"
//���յ�˵��������ʵ�ֵĲ������ݣ��������������
//���յء�UIί��ϵ��

UCLASS()
class AM_Controller :public APlayerController
{
	GENERATED_BODY()

public:
	AM_Controller();
<<<<<<< Updated upstream
	/*
	public:
	TSubClass<m_PLAYERSTATE> PLAYER
	*/
=======

public:
	//����ָ��
	class AM_Character* SPCharacter;
	class AM_PlayerState* SPState;

/*	���յء�UIί�б���
    ���յء������
	���յء����߼��
	���յء��ǽ�ɫ���� ��ESC\BagPack\Tallking��
	���յء�С��ͼ
*/
	void PlayerDead();

public:
	virtual void BeginPlay() override;
>>>>>>> Stashed changes

};