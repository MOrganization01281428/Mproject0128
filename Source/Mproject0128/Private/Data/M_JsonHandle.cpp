// Fill out your copyright notice in the Description page of Project Settings.


//#include "M_JsonHandle.h"
#include "..\..\Public\Data\M_JsonHandle.h"

M_JsonHandle::M_JsonHandle()
{
	RecordDataFileName = FString("RecordData.json");
	/*
	RecordDataFileName = FString("RecordData.json");
	ObjectAttrFileName = FString("ObjectAttribute.json");
	ResourceAttrFileName = FString("ResourceAttribute.json");
	CompoundTableFileName = FString("CompoundTable.json");
	RelativePath = FString("Res/ConfigData/");*/
}

M_JsonHandle::~M_JsonHandle()
{
}

void M_JsonHandle::RecordDataJsonRead(TArray<FString>& RecordDataList)
{
	FString JsonValue;
	LoadStringFromFile(RecordDataFileName, RelativePath, JsonValue);


	TArray<TSharedPtr<FJsonValue>> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed)) {

		//获取存档数据
		TArray<TSharedPtr<FJsonValue>> RecordDataArray = JsonParsed[3]->AsObject()->GetArrayField(FString("RecordData"));
		for (int i = 0; i < RecordDataArray.Num(); ++i) {
			FString RecordDataName = RecordDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			RecordDataList.Add(RecordDataName);
		}
	}

}

void M_JsonHandle::UpdateRecordData(TArray<FString>* RecordDataList)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	TArray<TSharedPtr<FJsonValue>> BaseDataArray;
	
	TArray<TSharedPtr<FJsonValue>> RecordDataArray;

	for (int i = 0; i < RecordDataList->Num(); ++i) {
		TSharedPtr<FJsonObject> RecordItem = MakeShareable(new FJsonObject);
		RecordItem->SetStringField(FString::FromInt(i), (*RecordDataList)[i]);
		TSharedPtr<FJsonValueObject> RecordDataValue = MakeShareable(new FJsonValueObject(RecordItem));
		RecordDataArray.Add(RecordDataValue);
	}

	TSharedPtr<FJsonObject> RecordDataObject = MakeShareable(new FJsonObject);
	RecordDataObject->SetArrayField("RecordData", RecordDataArray);
	TSharedPtr<FJsonValueObject> RecordDataValue = MakeShareable(new FJsonValueObject(RecordDataObject));

	BaseDataArray.Add(RecordDataValue);

	JsonObject->SetArrayField("T", BaseDataArray);

	FString JsonStr;
	GetFStringInJsonData(JsonObject, JsonStr);

	//SlAiHelper::Debug(FString("Origin Str : " + JsonStr), 60.f);

	//去掉多余字符
	JsonStr.RemoveAt(0, 8);
	JsonStr.RemoveFromEnd(FString("}"));

	//SlAiHelper::Debug(FString("Final Str : " + JsonStr), 60.f);

	//写入文件
	WriteFileWithJsonData(JsonStr, RelativePath, RecordDataFileName);

}

bool M_JsonHandle::GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr)
{
	if (JsonObj.IsValid() && JsonObj->Values.Num() > 0)
	{
		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonStr);
		FJsonSerializer::Serialize(JsonObj.ToSharedRef(), JsonWriter);
		return true;
	}
	return false;
}

bool M_JsonHandle::WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName)
{
	if (!JsonStr.IsEmpty()) {
		if (!FileName.IsEmpty()) {
			FString AbsoPath = FPaths::GameContentDir() + RelaPath + FileName;
			//保存
			if (FFileHelper::SaveStringToFile(JsonStr, *AbsoPath)) {

				return true;
			}
			else {
				//SlAiHelper::Debug(FString("Save") + AbsoPath + FString("-->Failed"), 10.f);
			}
		}

	}
	return false;
}

bool M_JsonHandle::LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString)
{
		if (!FileName.IsEmpty()) {
		//获取绝对路径
		FString AbsoPath = FPaths::GameContentDir() + RelaPath + FileName;
		if (FPaths::FileExists(AbsoPath)) {
			if (FFileHelper::LoadFileToString(ResultString, *AbsoPath))
			{
				return true;
			}
			else {
				//加载不成功
				//SlAiHelper::Debug(FString("Load Error") + AbsoPath);
			}
		}
		else {
			//输出文件不存在
			//SlAiHelper::Debug(FString("File Not Exist") + AbsoPath);
		}
	}
	return false;
}
