
#include "M_GameMode.h"
#include "M_Character.h"
#include "M_Controller.h"
#include "M_PlayerState.h"

//#include "M_DataHandle.h"
#include "..\..\Public\Data\M_DataHandle.h"
#include "M_GameInstance.h"
#include "M_SaveGame.h"

#include "Kismet/GameplayStatics.h"

AM_GameMode::AM_GameMode()
{

}

void AM_GameMode::InicialGameMode()
{/*
	//如果控制器指针为空,添加引用//重复声明，如有必要删除
	if (!SPController) SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!SPCharacter) SPCharacter = Cast<AM_Character>(GetCharacter());
	if (!SPState) SPState = Cast<AM_PlayerState>(PlayerState);
	*/
}


/*
void AM_GameMode::SaveGame()
{
	UM_SaveGame* NewRecord = Cast<UM_SaveGame>(UGameplayStatic::CreateSaveGameObject(UM_SaveGame::StaticClass()));

	NewRecord->PlayerMana = SPController->SPState->getMana;
	NewRecord->PlayerHP = SPController->SPState->getHealth;

	//保存存档
	UGameplayStatics::SaveGameToSlot(NewRecord, "Save1", 0);

	/*
	//如果存档名是Default,不进行保存
	if (SlAiDataHandle::Get()->RecordName.Equals(FString("Default"))) return;



	//创建一个新的存档
	USlAiSaveGame* NewRecord = Cast<USlAiSaveGame>(UGameplayStatics::CreateSaveGameObject(USlAiSaveGame::StaticClass()));

	//对存档进行赋值
	//设置玩家位置和血量
	NewRecord->PlayerLocation = SPCharacter->GetActorLocation();
	SPState->SaveState(NewRecord->PlayerHP, NewRecord->PlayerHunger);

	//循环设置敌人
	for (TActorIterator<ASlAiEnemyCharacter> EnemyIt(GetWorld()); EnemyIt; ++EnemyIt)
	{
		NewRecord->EnemyLoaction.Add((*EnemyIt)->GetActorLocation());
		NewRecord->EnemyHP.Add((*EnemyIt)->GetHP());
	}

	//循环设置岩石
	for (TActorIterator<ASlAiResourceRock> RockIt(GetWorld()); RockIt; ++RockIt)
	{
		NewRecord->ResourceRock.Add((*RockIt)->GetActorLocation());
	}

	//循环设置树木
	for (TActorIterator<ASlAiResourceTree> TreeIt(GetWorld()); TreeIt; ++TreeIt) {
		NewRecord->ResourceTree.Add((*TreeIt)->GetActorLocation());
	}

	//循环设置拾取物品石头
	for (TActorIterator<ASlAiPickupStone> StoneIt(GetWorld()); StoneIt; ++StoneIt) {
		NewRecord->PickupStone.Add((*StoneIt)->GetActorLocation());
	}

	//循环设置拾取物品木头
	for (TActorIterator<ASlAiPickupWood> WoodIt(GetWorld()); WoodIt; ++WoodIt) {
		NewRecord->PickupWood.Add((*WoodIt)->GetActorLocation());
	}

	//获取背包数据
	SlAiPackageManager::Get()->SaveData(NewRecord->InputIndex, NewRecord->InputNum, NewRecord->NormalIndex, NewRecord->NormalNum, NewRecord->ShortcutIndex, NewRecord->ShortcutNum);

	//查看是否已经有存档存在
	if (UGameplayStatics::DoesSaveGameExist(SlAiDataHandle::Get()->RecordName, 0)) {
		//有的话先删除
		UGameplayStatics::DeleteGameInSlot(SlAiDataHandle::Get()->RecordName, 0);
	}
	//保存存档
	UGameplayStatics::SaveGameToSlot(NewRecord, SlAiDataHandle::Get()->RecordName, 0);

	//查看json是否已经有这个存档
	bool IsRecordExist = false;
	for (TArray<FString>::TIterator It(SlAiDataHandle::Get()->RecordDataList); It; ++It)
	{
		//只要有一个相同,就跳出
		if ((*It).Equals(SlAiDataHandle::Get()->RecordName)) {
			IsRecordExist = true;
			break;
		}
	}
	//如果存档不存在,让数据管理类添加存档到json
	if (!IsRecordExist) SlAiDataHandle::Get()->AddNewRecord();

		//查看是否已经有存档存在
	if (UGameplayStatics::DoesSaveGameExist(SlAiDataHandle::Get()->RecordName, 0)) {
		//有的话先删除
		UGameplayStatics::DeleteGameInSlot(SlAiDataHandle::Get()->RecordName, 0);
	}

	//查看json是否已经有这个存档
	bool IsRecordExist = false;
	for (TArray<FString>::TIterator It(SlAiDataHandle::Get()->RecordDataList); It; ++It)
	{
		//只要有一个相同,就跳出
		if ((*It).Equals(SlAiDataHandle::Get()->RecordName)) {
			IsRecordExist = true;
			break;
		}
	}
	//如果存档不存在,让数据管理类添加存档到json
	if (!IsRecordExist) SlAiDataHandle::Get()->AddNewRecord();

	
}

void AM_GameMode::LoadGame()
{
}
*///暂时废弃内容
void AM_GameMode::BeginPlay()
{
	Super::BeginPlay();

	//SaveInstance = Cast<UM_SaveGame>(UGameplayStatics::CreateSaveGameObject(UESaveGame::StaticClass()));

	//初始化游戏数据
	//M_DataHandle::Get()->InitializeGameData();
	//if (!SPController) InitGameModule();
	
}
