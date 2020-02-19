// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Json.h"

/**
 * 
 */
class MPROJECT0128_API M_JsonHandle
{
public:
	M_JsonHandle();
	~M_JsonHandle();

	//�����浵����
	void RecordDataJsonRead(TArray<FString>& RecordDataList);

	//�޸Ĵ浵
	void UpdateRecordData(TArray<FString>* RecordDataList);


	//FJsonObjectת��ΪJson��ʽ���ַ���
	bool GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr);

	//�����ַ������ļ�
	bool WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName);

	//��ȡJson�ļ����ַ���
	bool LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString);
	//�浵�ļ���
	FString RecordDataFileName;
	//���·��
	FString RelativePath;
};
