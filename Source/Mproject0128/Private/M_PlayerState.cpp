#include "M_PlayerState.h"

#include "Kismet/GameplayStatics.h"
#include "M_Controller.h"

AM_PlayerState::AM_PlayerState()
{
	Health = 100.0f;
	Mana = 100.0f;
}

void AM_PlayerState::setHealth(float value)
{
	Health = value;
}

void AM_PlayerState::setMana(float value)
{
	Health = value;
}
