#include "M_PlayerState.h"
#include "M_Controller.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
//��ֵ��ʼ��
AM_PlayerState::AM_PlayerState()
{
	Health = 1000.0f;
	Mana = 1000.0f;
}
//���û�ȡ
void AM_PlayerState::BeginPlay()
{
	Super::BeginPlay();
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}
//��ֵ�趨default����
void AM_PlayerState::setHealth(float value)
{
	Health = value;
}

float AM_PlayerState::getHealth()
{
	return Health;
}

void AM_PlayerState::setMana(float value)
{
	Health = value;
}
//��ɫ�˺��������޸�����ֵ
void AM_PlayerState::AcceptDamage(int DamageVal)
{
	Health = FMath::Clamp<float>(Health - DamageVal, 0.f, 500.f);
	//���Ѫֵ����0����û��
	if (Health == 0 && !IsDead)
	{
		//���߿������Լ�����
		if (SPController) SPController->PlayerDead();
		IsDead = true;
	}
}
//��ɫ���������޸�
bool AM_PlayerState::IsPlayerDead()
{
	return false;
}

void AM_PlayerState::OnRecoverMana(float Recover)
{
		FPlatformProcess::Sleep(100);
		Mana = Mana + Recover;
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black,FString::Printf(Mana));
	
}

void AM_PlayerState::OnCostMana(float Cost)
{
	FPlatformProcess::Sleep(Cost);
	Mana = Mana + Cost;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black,"[OnCostMana]: Mana Has change");
}

void AM_PlayerState::SaveState(float& HP, float& MP)
{
	
	HP = Health;
	MP = Mana;

	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("[SaveGame] success!"));

}

void AM_PlayerState::LoadState(float HP, float MP)
{
	Health = HP;
	Mana = MP;
}
