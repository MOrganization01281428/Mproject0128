#include "M_GameMode.h"
#include "M_MainMenuHUD.h"
#include "M_Controller.h"

AM_GameMode::AM_GameMode()
{
	HUDClass = AM_MainMenuHUD::StaticClass();
	PlayerControllerClass = AM_Controller::StaticClass();

}