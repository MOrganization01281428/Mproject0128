
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
	//���������ָ��Ϊ��,�������//�ظ����������б�Ҫɾ��
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

	//����浵
	UGameplayStatics::SaveGameToSlot(NewRecord, "Save1", 0);

	/*
	//����浵����Default,�����б���
	if (SlAiDataHandle::Get()->RecordName.Equals(FString("Default"))) return;



	//����һ���µĴ浵
	USlAiSaveGame* NewRecord = Cast<USlAiSaveGame>(UGameplayStatics::CreateSaveGameObject(USlAiSaveGame::StaticClass()));

	//�Դ浵���и�ֵ
	//�������λ�ú�Ѫ��
	NewRecord->PlayerLocation = SPCharacter->GetActorLocation();
	SPState->SaveState(NewRecord->PlayerHP, NewRecord->PlayerHunger);

	//ѭ�����õ���
	for (TActorIterator<ASlAiEnemyCharacter> EnemyIt(GetWorld()); EnemyIt; ++EnemyIt)
	{
		NewRecord->EnemyLoaction.Add((*EnemyIt)->GetActorLocation());
		NewRecord->EnemyHP.Add((*EnemyIt)->GetHP());
	}

	//ѭ��������ʯ
	for (TActorIterator<ASlAiResourceRock> RockIt(GetWorld()); RockIt; ++RockIt)
	{
		NewRecord->ResourceRock.Add((*RockIt)->GetActorLocation());
	}

	//ѭ��������ľ
	for (TActorIterator<ASlAiResourceTree> TreeIt(GetWorld()); TreeIt; ++TreeIt) {
		NewRecord->ResourceTree.Add((*TreeIt)->GetActorLocation());
	}

	//ѭ������ʰȡ��Ʒʯͷ
	for (TActorIterator<ASlAiPickupStone> StoneIt(GetWorld()); StoneIt; ++StoneIt) {
		NewRecord->PickupStone.Add((*StoneIt)->GetActorLocation());
	}

	//ѭ������ʰȡ��Ʒľͷ
	for (TActorIterator<ASlAiPickupWood> WoodIt(GetWorld()); WoodIt; ++WoodIt) {
		NewRecord->PickupWood.Add((*WoodIt)->GetActorLocation());
	}

	//��ȡ��������
	SlAiPackageManager::Get()->SaveData(NewRecord->InputIndex, NewRecord->InputNum, NewRecord->NormalIndex, NewRecord->NormalNum, NewRecord->ShortcutIndex, NewRecord->ShortcutNum);

	//�鿴�Ƿ��Ѿ��д浵����
	if (UGameplayStatics::DoesSaveGameExist(SlAiDataHandle::Get()->RecordName, 0)) {
		//�еĻ���ɾ��
		UGameplayStatics::DeleteGameInSlot(SlAiDataHandle::Get()->RecordName, 0);
	}
	//����浵
	UGameplayStatics::SaveGameToSlot(NewRecord, SlAiDataHandle::Get()->RecordName, 0);

	//�鿴json�Ƿ��Ѿ�������浵
	bool IsRecordExist = false;
	for (TArray<FString>::TIterator It(SlAiDataHandle::Get()->RecordDataList); It; ++It)
	{
		//ֻҪ��һ����ͬ,������
		if ((*It).Equals(SlAiDataHandle::Get()->RecordName)) {
			IsRecordExist = true;
			break;
		}
	}
	//����浵������,�����ݹ�������Ӵ浵��json
	if (!IsRecordExist) SlAiDataHandle::Get()->AddNewRecord();

		//�鿴�Ƿ��Ѿ��д浵����
	if (UGameplayStatics::DoesSaveGameExist(SlAiDataHandle::Get()->RecordName, 0)) {
		//�еĻ���ɾ��
		UGameplayStatics::DeleteGameInSlot(SlAiDataHandle::Get()->RecordName, 0);
	}

	//�鿴json�Ƿ��Ѿ�������浵
	bool IsRecordExist = false;
	for (TArray<FString>::TIterator It(SlAiDataHandle::Get()->RecordDataList); It; ++It)
	{
		//ֻҪ��һ����ͬ,������
		if ((*It).Equals(SlAiDataHandle::Get()->RecordName)) {
			IsRecordExist = true;
			break;
		}
	}
	//����浵������,�����ݹ�������Ӵ浵��json
	if (!IsRecordExist) SlAiDataHandle::Get()->AddNewRecord();

	
}

void AM_GameMode::LoadGame()
{
}
*///��ʱ��������
void AM_GameMode::BeginPlay()
{
	Super::BeginPlay();

	//SaveInstance = Cast<UM_SaveGame>(UGameplayStatics::CreateSaveGameObject(UESaveGame::StaticClass()));

	//��ʼ����Ϸ����
	//M_DataHandle::Get()->InitializeGameData();
	//if (!SPController) InitGameModule();
	
}
