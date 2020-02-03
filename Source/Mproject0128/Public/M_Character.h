#pragma once

#include "CoreMinimal.h"//核心引用文件，未包含可能会带来未知错误
#include "GameFramework/Character.h"//继承角色类
#include "M_MagicBullet.h"

#include "M_Character.generated.h"//生成的编译文件，总是要放在最后的

class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class AM_MagicBullet;

UCLASS(Blueprintable)
class AM_Character :public ACharacter
{
	GENERATED_BODY()

public:
	AM_Character();

//关联的实体类：Magic实体、道具装备、Buff外衣等；
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
		TSubclassOf<AM_MagicBullet> MagicBulletClass;
//关联控制类：数据处理，玩家（非角色）控制
	/*

	*/

//组件挂载
	UPROPERTY(EditAnywhere, Category = "Mesh")
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = "Magic")
		UStaticMeshComponent* MagicSlotComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
		USpringArmComponent* CameraArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* Camera;



	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


	//基础控制行为函数组：
	UFUNCTION(BlueprintCallable)
		void MoveForward(float value);
	UFUNCTION(BlueprintCallable)
		void MoveLeft(float value);
	UFUNCTION(BlueprintCallable)
		void LookUp(float value);
	UFUNCTION(BlueprintCallable)
		void LookRight(float value);
	UFUNCTION(BlueprintCallable)
		void OnStartJump();
	UFUNCTION(BlueprintCallable)
		void OnStopJump();

	//特性控制行为函数组
	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void OnStartMeditation();


	//virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

};