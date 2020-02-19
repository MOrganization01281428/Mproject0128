// Fill out your copyright notice in the Description page of Project Settings.


#include "M_EnemyCharacter.h"
#include "M_EnemyAIController.h"

// Sets default values
AM_EnemyCharacter::AM_EnemyCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AM_EnemyAIController::StaticClass();

}

// Called when the game starts or when spawned
void AM_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	SEController = Cast<AM_EnemyAIController>(GetController());
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

}

void AM_EnemyCharacter::IsLockPlayer()
{
}
