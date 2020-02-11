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

	//解析存档方法
	void RecordDataJsonRead(FString& Culture, float& MusicVolume, float& SoundVolume, TArray<FString>& RecordDataList);

	//修改存档
	void UpdateRecordData(FString Culture, float MusicVolume, float SoundVolume, TArray<FString>* RecordDataList);


	//读取Json文件到字符串
	bool LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString);
	//存档文件名
	FString RecordDataFileName;

};
