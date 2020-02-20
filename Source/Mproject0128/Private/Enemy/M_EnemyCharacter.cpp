// Fill out your copyright notice in the Description page of Project Settings.


#include "M_EnemyCharacter.h"
#include "M_EnemyAIController.h"
#include "GameFramework/Actor.h"

// Sets default values
AM_EnemyCharacter::AM_EnemyCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AM_EnemyAIController::StaticClass();
	SEController = Cast<AM_EnemyAIController>(GetController());

}

// Called when the game starts or when spawned
void AM_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	HP = 100;

}

// Called every frame
void AM_EnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AM_EnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AM_EnemyCharacter::AcceptDamage(int DamageVal)
{

	//进行血值更新
	HP = FMath::Clamp<float>(HP - DamageVal, 0.f, 500.f);

	if (HP <= 0.f)
	{
		//告诉控制器死亡
		SEController->EnemyDead();
		AM_EnemyCharacter::DestroyEvent();
	}
	
}

void AM_EnemyCharacter::DestroyEvent()
{
	GetWorld()->DestroyActor(this);
}

void AM_EnemyCharacter::OnSeePlayer(APawn* PlayerChar)
{
	if (Cast<AM_Character>(PlayerChar)) {

		//告诉控制器我看到玩家了
		if (SEController) SEController->OnSeePlayer();
	}

}
bool AM_EnemyCharacter::IsLockPlayer()
{
	if (SEController) return SEController->IsLockPlayer;
	return false;
}

float AM_EnemyCharacter::GetIdleWaitTime()
{
		//如果动作蓝图不存在直接返回3秒暂时没有动画，统一返回4秒
	//if (!SEAnim) return 3.f;
	//创建随机流
	FRandomStream Stream;
	Stream.GenerateNewSeed();
	int IdleTpye = Stream.RandRange(0, 2);
	//float AnimLength = SEAnim->SetIdelType(IdleTpye);
	//更新种子
	Stream.GenerateNewSeed();
	//产生动作次数
	int AnimCount = Stream.RandRange(1, 3);
	//返回全部的动画时长
	return 4.0f;
	//return AnimLength * AnimCount;
}
