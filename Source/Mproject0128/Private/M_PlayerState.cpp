#include "M_PlayerState.h"

#include "TimerManager.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"

#include "M_Character.h"
#include "M_Controller.h"

#include "Kismet/GameplayStatics.h"


//DEFINE_LOG_CATEGORY(YourLog);
AM_PlayerState::AM_PlayerState()
{
	Health = 100.0f;
	Mana = 100.0f;
}

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

float AM_PlayerState::getMana()
{
	return Mana;
}

void AM_PlayerState::OnRecoverMana(float Recover)
{
	while (IsMeditation)
	{
		FPlatformProcess::Sleep(100);
		Mana = Mana + Recover;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, FString::SanitizeFloat(Mana));
	}
}

void AM_PlayerState::OnCostMana(float Cost)
{
	FPlatformProcess::Sleep(Cost);
	Mana = Mana + Cost;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, FString::SanitizeFloat(Mana));
}

bool AM_PlayerState::SetIsMeditation(bool IsMeditation)
{
	return  IsMeditation;
}

void AM_PlayerState::SaveGame(FString SlotName)
{
	//创建一个存档插槽保存自定义的存档实例
	UGameplayStatics::SaveGameToSlot(SaveInstance, SlotName, 0);

	/*添加到存档角色Transform信息
	ESaveInstance->ESPlayerStructInfo.PlayerTrans.SetLocation(this->GetActorLocation());
	ESaveInstance->ESPlayerStructInfo.PlayerTrans.SetRotation(this->GetActorRotation().Quaternion());
	ESaveInstance->ESPlayerStructInfo.PlayerTrans.SetScale3D(this->GetActorScale3D());
	*/
	//添加到存档角色Health\Mana
	SaveInstance->SPlayerStructInfo.PlayerHealth = Health;
	SaveInstance->SPlayerStructInfo.PlayerMana = Mana;

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("游戏已经存档"));

}
void AM_PlayerState::LoadGame(FString SlotName)
{
	if (SlotName == SlotName)
	{
		//从存档实例中取出保存的数据
		UGameplayStatics::LoadGameFromSlot(SlotName, 0);

		/*//读取存档角色Transform信息
		this->SetActorLocation(ESaveInstance->ESPlayerStructInfo.PlayerTrans.GetLocation());
		this->SetActorRotation(ESaveInstance->ESPlayerStructInfo.PlayerTrans.GetRotation());
		this->SetActorScale3D(ESaveInstance->ESPlayerStructInfo.PlayerTrans.GetScale3D());
		*/
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("读取存档成功"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("没有找到存档"));

	}

}

void AM_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	//如果控制器指针为空,添加引用
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));//已经在Character中获得

}
