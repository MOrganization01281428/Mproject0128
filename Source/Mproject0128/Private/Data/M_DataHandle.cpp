
#include "M_DataHandle.h"
#include "M_Singleton.h"
#include "M_Singleton.h"
#include "M_JsonHandle.h"

M_DataHandle::M_DataHandle()
{
	/*	//初始化存档数据*/
	InicialRecordData();
}

void M_DataHandle::InicialRecordData()
{
	M_Singleton<M_JsonHandle>::Get()->RecordDataJsonRead(RecordDataList);


	FString Culture;
	//读取存档数据
	M_Singleton<M_JsonHandle>::Get()->RecordDataJsonRead(RecordDataList);

}

void M_DataHandle::InicialGameData()
{
	//暂无
}

void M_DataHandle::AddNewRecord()
{
	
	//将现在的存档名添加到数组
	RecordDataList.Add(RecordName);
	//更新json数据
	M_Singleton<M_JsonHandle>::Get()->UpdateRecordData(&RecordDataList);

}
