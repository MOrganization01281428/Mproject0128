// Fill out your copyright notice in the Description page of Project Settings.


//#include "M_DataHandle.h"��Bug�㣬���ܺ�������ͷ�ļ��������
#include "M_Singleton.h"
#include "..\..\Public\Data\M_DataHandle.h"

M_DataHandle::M_DataHandle()
{
	/*	//��ʼ���浵����
	InitRecordData();*/
}

M_DataHandle::~M_DataHandle()
{
}

void M_DataHandle::InicialRecordData()
{
	//��ȡ�浵����M_Singleton<M_JsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);

	/*
	RecordName = FString("");
	//��ȡ����
	FString Culture;
	//��ȡ�浵����
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);

	//��ʼ������
	ChangeLocalizationCulture(GetEnumValueFromString<ECultureTeam>(FString("ECultureTeam"), Culture));*/
}

void M_DataHandle::InicialGameData()
{
	//����
}

void M_DataHandle::AddNewRecord()
{
	/*
		//�����ڵĴ浵����ӵ�����
	RecordDataList.Add(RecordName);
	//����json����
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);
*/
}
