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
	//����һ���浵��۱����Զ���Ĵ浵ʵ��
	UGameplayStatics::SaveGameToSlot(SaveInstance, SlotName, 0);

	/*��ӵ��浵��ɫTransform��Ϣ
	ESaveInstance->ESPlayerStructInfo.PlayerTrans.SetLocation(this->GetActorLocation());
	ESaveInstance->ESPlayerStructInfo.PlayerTrans.SetRotation(this->GetActorRotation().Quaternion());
	ESaveInstance->ESPlayerStructInfo.PlayerTrans.SetScale3D(this->GetActorScale3D());
	*/
	//��ӵ��浵��ɫHealth\Mana
	SaveInstance->SPlayerStructInfo.PlayerHealth = Health;
	SaveInstance->SPlayerStructInfo.PlayerMana = Mana;

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("��Ϸ�Ѿ��浵"));

}
void AM_PlayerState::LoadGame(FString SlotName)
{
	if (SlotName == SlotName)
	{
		//�Ӵ浵ʵ����ȡ�����������
		UGameplayStatics::LoadGameFromSlot(SlotName, 0);

		/*//��ȡ�浵��ɫTransform��Ϣ
		this->SetActorLocation(ESaveInstance->ESPlayerStructInfo.PlayerTrans.GetLocation());
		this->SetActorRotation(ESaveInstance->ESPlayerStructInfo.PlayerTrans.GetRotation());
		this->SetActorScale3D(ESaveInstance->ESPlayerStructInfo.PlayerTrans.GetScale3D());
		*/
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("��ȡ�浵�ɹ�"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("û���ҵ��浵"));

	}

}

void AM_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	//���������ָ��Ϊ��,�������
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));//�Ѿ���Character�л��

}
