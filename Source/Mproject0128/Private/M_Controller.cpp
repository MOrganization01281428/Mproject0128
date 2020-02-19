#include "M_Controller.h"
#include "M_PlayerState.h"
#include "M_Character.h"
//Controller说明
//创建了几个指针引用，并且在BeginPlaye里获取实例，仅此而已。
AM_Controller::AM_Controller()
{

}

void AM_Controller::BeginPlay()
{
	Super::BeginPlay();
	if (!SPCharacter) SPCharacter = Cast<AM_Character>(GetCharacter());
	if (!SPState) SPState = Cast<AM_PlayerState>(PlayerState);
}

void AM_Controller::Tick(float DeltaSeconds)
{
}

void AM_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftClick", IE_Pressed, this, &AM_Controller::LeftClickStart);
	InputComponent->BindAction("LeftClick", IE_Released, this, &AM_Controller::LeftClickStop);
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AM_Controller::RightClickStart);
	InputComponent->BindAction("RightClick", IE_Released, this, &AM_Controller::RightClickStop);
	InputComponent->BindAction("ScrollUp", IE_Pressed, this, &AM_Controller::RollUpEvent);
	InputComponent->BindAction("ScrollDown", IE_Pressed, this, &AM_Controller::RollDownEvent);
	InputComponent->BindAction("ESC", IE_Pressed, this, &AM_Controller::EscEvent).bExecuteWhenPaused = true;

}

void AM_Controller::LeftClickStart()
{
}

void AM_Controller::LeftClickStop()
{
}

void AM_Controller::RightClickStart()
{
}

void AM_Controller::RightClickStop()
{
}

void AM_Controller::RollUpEvent()
{
}

void AM_Controller::RollDownEvent()
{
}

void AM_Controller::EscEvent()
{
}

void AM_Controller::PlayerDead()
{
}
