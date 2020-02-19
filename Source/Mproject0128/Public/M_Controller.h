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
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;



public:
	//鼠标Click事件
	void LeftClickStart();
	void LeftClickStop();
	void RightClickStart();
	void RightClickStop();
	//滚轮上下滚动事件
	void RollUpEvent();
	void RollDownEvent();
	//ESC事件
	void EscEvent();

public:
	//引用指针
	class AM_Character* SPCharacter;
	class AM_PlayerState* SPState;

	void PlayerDead();



};