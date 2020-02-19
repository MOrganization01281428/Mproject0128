
#include "M_DataHandle.h"
#include "M_Singleton.h"
#include "M_Singleton.h"
#include "M_JsonHandle.h"

M_DataHandle::M_DataHandle()
{
	/*	//��ʼ���浵����*/
	InicialRecordData();
}

void M_DataHandle::InicialRecordData()
{
	M_Singleton<M_JsonHandle>::Get()->RecordDataJsonRead(RecordDataList);


	FString Culture;
	//��ȡ�浵����
	M_Singleton<M_JsonHandle>::Get()->RecordDataJsonRead(RecordDataList);

}

void M_DataHandle::InicialGameData()
{
	//����
}

void M_DataHandle::AddNewRecord()
{
	
	//�����ڵĴ浵�����ӵ�����
	RecordDataList.Add(RecordName);
	//����json����
	M_Singleton<M_JsonHandle>::Get()->UpdateRecordData(&RecordDataList);

}
