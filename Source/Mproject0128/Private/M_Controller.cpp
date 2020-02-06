#include "M_Controller.h"

AM_Controller::AM_Controller()
{
public:

	AM_Controller();

}

void AM_Controller::PlayerDead()
{
}

void AM_Controller::BeginPlay()
{
	Super::BeginPlay();
	//获取角色与状态
	if (!SPCharacter) SPCharacter = Cast<AM_Character>(GetCharacter());
	if (!SPState) SPState = Cast<AM_PlayerState>(PlayerState);

}
