// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<class T>
class MPROJECT0128_API M_Singleton
{

public:
	static void Initialize();
	static TSharedPtr<T> Get();
	static TSharedRef<T> Create();
	static TSharedPtr<T> TInstance;

};
//����ģ�壬��ģ�彫�ܹ��������඼�ܹ�ʹ�������ĺ���
//ģ������һ������ָ�뺯�����ô����ǻ�ȡһ��T���͵����á�

template<class T>
TSharedPtr<T> M_Singleton<T>::TInstance = NULL;

template<class T>
TSharedRef<T> M_Singleton<T>::Create()
{
	TSharedRef<T> TRef = MakeShareable(new T());
	return TRef;
}

template<class T>
void M_Singleton<T>::Initialize()
{
	if (!TInstance.IsValid()) {
		TInstance = Create();
	}
}

template<class T>
TSharedPtr<T> M_Singleton<T>::Get()
{
	Initialize();
	return TInstance;
}

