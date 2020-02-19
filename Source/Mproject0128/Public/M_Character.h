#pragma once

#include "CoreMinimal.h"//核心引用文件，未包含可能会带来未知错误
#include "GameFramework/Character.h"//继承角色类
#include "M_MagicBullet.h"
#include "M_Controller.h"

#include "M_Character.generated.h"//生成的编译文件，总是要放在最后的

class USkeletalMeshComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class AM_MagicBullet;


UCLASS(Blueprintable)
class AM_Character :public ACharacter
{
	GENERATED_BODY()

public:
//构建与初始化
	AM_Character();
	virtual void BeginPlay() override;


//数据通信

	TSubclassOf<AActor> MatchBPMgaicActor;

	class AM_Controller* SPController;


//组件挂载
	UPROPERTY(EditAnywhere, Category = "Mesh")
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = "Camera")
		USpringArmComponent* CameraArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Magic")
		UStaticMeshComponent* MagicSlotComponent;

//行为绑定
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

//基础控制行为函数组：
	UFUNCTION(BlueprintCallable,Category = "Control")
		void MoveForward(float value);
	UFUNCTION(BlueprintCallable,Category = "Control")
		void MoveLeft(float value);
	UFUNCTION(BlueprintCallable,Category = "Control")
		void LookUp(float value);
	UFUNCTION(BlueprintCallable,Category = "Control")
		void LookRight(float value);
	UFUNCTION(BlueprintCallable,Category = "Control")
		void OnStartJump();
	UFUNCTION(BlueprintCallable,Category = "Control")
		void OnStopJump();

//特性控制行为函数组
	UFUNCTION(BlueprintCallable,Category = "Control")
		void Fire();
	UFUNCTION(BlueprintCallable, Category = "Control")
		bool IsDead();
	UFUNCTION(BlueprintCallable, Category = "Control")
		void AcceptDamage(int DamageVal);

};