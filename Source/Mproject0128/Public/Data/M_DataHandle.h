// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MPROJECT0128_API M_DataHandle
{
public:
	M_DataHandle();
	~M_DataHandle();
public:
	
	void InicialRecordData();
	void InicialGameData();
	void AddNewRecord();
public:
	FString RecordName;
	FString DefaultRecordName = "SaveOne";

};
