#include "M_PlayerState.h"
#include "M_Controller.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
//数值初始化
AM_PlayerState::AM_PlayerState()
{
	Health = 1000.0f;
	Mana = 1000.0f;
}
//引用获取
void AM_PlayerState::BeginPlay()
{
	Super::BeginPlay();
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}
//数值设定default函数
void AM_PlayerState::setHealth(float value)
{
	Health = value;
}

void AM_PlayerState::setMana(float value)
{
	Health = value;
}
//角色伤害处理，修改生命值
void AM_PlayerState::AcceptDamage(int DamageVal)
{
	Health = FMath::Clamp<float>(Health - DamageVal, 0.f, 500.f);
	//如果血值等于0但是没死
	if (Health == 0 && !IsDead)
	{
		//告诉控制器自己死了
		if (SPController) SPController->PlayerDead();
		IsDead = true;
	}
}
//角色死亡属性修改
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
