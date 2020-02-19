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
//创建模板，该模板将能够让所有类都能够使用声明的函数
//模板中这一套智能指针函数，用处就是获取一个T类型的引用。

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

