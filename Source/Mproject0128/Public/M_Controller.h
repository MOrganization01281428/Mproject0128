#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "M_Controller.generated.h"
//【空地说明】即将实现的部分内容，包含方法与变量
//【空地】UI委托系列

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
	//引用指针
	class AM_Character* SPCharacter;
	class AM_PlayerState* SPState;

/*	【空地】UI委托变量
    【空地】鼠标检测
	【空地】射线检测
	【空地】非角色按键 （ESC\BagPack\Tallking）
	【空地】小地图
*/
	void PlayerDead();

public:
	virtual void BeginPlay() override;
>>>>>>> Stashed changes

};