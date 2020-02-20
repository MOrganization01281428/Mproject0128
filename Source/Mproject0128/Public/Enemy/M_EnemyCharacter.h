// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "M_EnemyCharacter.generated.h"


UCLASS()
class MPROJECT0128_API AM_EnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AM_EnemyCharacter();


public:	

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
		class AM_EnemyAIController* SEController;

public:
	//敌人感知
	UPROPERTY(EditAnywhere, Category = "Mesh")
		class UPawnSensingComponent* EnemySense;
public:
	void AcceptDamage(int DamageVal);
	void DestroyEvent();

	//行为树模块
	void OnSeePlayer(APawn* PlayerChar);
	bool IsLockPlayer();
	//获取Idle等待时长
	float GetIdleWaitTime();

public:
	float HP;

};
