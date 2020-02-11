// Fill out your copyright notice in the Description page of Project Settings.


//#include "M_DataHandle.h"▲Bug点，可能后期引用头文件会出问题
#include "M_Singleton.h"
#include "..\..\Public\Data\M_DataHandle.h"

M_DataHandle::M_DataHandle()
{
	/*	//初始化存档数据
	InitRecordData();*/
}

M_DataHandle::~M_DataHandle()
{
}

void M_DataHandle::InicialRecordData()
{
	//读取存档数据M_Singleton<M_JsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);

	/*
	RecordName = FString("");
	//获取语言
	FString Culture;
	//读取存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);

	//初始化语言
	ChangeLocalizationCulture(GetEnumValueFromString<ECultureTeam>(FString("ECultureTeam"), Culture));*/
}

void M_DataHandle::InicialGameData()
{
	//暂无
}

void M_DataHandle::AddNewRecord()
{
	/*
		//将现在的存档名添加到数组
	RecordDataList.Add(RecordName);
	//更新json数据
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
*/
}
