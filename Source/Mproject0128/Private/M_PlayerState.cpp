#include "M_PlayerState.h"

#include "Kismet/GameplayStatics.h"
#include "M_Controller.h"

<<<<<<< Updated upstream
=======
//PlayerState介绍
/*
数据内存储与
角色的变量与
	Set/Get函数：
	Health
	Mana
数据存档
通信：
链接SaveGame导入数据/加载数据；


*/
//DEFINE_LOG_CATEGORY(YourLog);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======

float AM_PlayerState::getMana()
{
	return Mana;
}

void AM_PlayerState::OnRecoverMana(float Recover)
{
		FPlatformProcess::Sleep(100);
		Mana = Mana + Recover;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black,FString::Printf(Mana));
	
}

void AM_PlayerState::OnCostMana(float Cost)
{
	FPlatformProcess::Sleep(Cost);
	Mana = Mana + Cost;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black,"[OnCostMana]: Mana Has change");
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

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("[SaveGame] success!"));

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
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("[LoadGame]Load Success"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("[LoadGame]No Found"));

	}

}

void AM_PlayerState::BeginPlay()
{
	Super::BeginPlay();
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}

