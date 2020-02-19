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
	//µÐÈË¸ÐÖª
	UPROPERTY(EditAnywhere, Category = Mesh)
		class UPawnSensingComponent* EnemySense;
public:
	void AcceptDamage(int DamageVal);
	void DestroyEvent();
	void OnSeePlayer(APawn* PlayerChar);
	void IsLockPlayer();
public:
	float HP;

};
