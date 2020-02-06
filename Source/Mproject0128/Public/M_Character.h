#pragma once

#include "CoreMinimal.h"//核心引用文件，未包含可能会带来未知错误
#include "GameFramework/Character.h"//继承角色类

#include "M_MagicBullet.h"
#include "M_Controller.h"
#include "M_PlayerState.h"

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

//蓝图类
	//实体类引用
	TSubclassOf<AActor> MatchBPMgaicActor;//这个指针将装载获取的蓝图类引用，我们口头规定只在匹配蓝图类BPMgaicActor时使用；

//关联的实体类：Magic实体、道具装备、Buff外衣等；但是显然我们要使用的是他的蓝图子类，这里下面的几行是没用的
//	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
//		TSubclassOf<AM_MagicBullet> MagicBulletClass;	
//		UClass* bpCLass;
	//UPROPERTY(EditDefaultsOnly, Category = "PlayerState")
	//TSubclassOf<APlayerState> PlayerState;


//关联控制类：数据处理，玩家（非角色）控制
	
	class AM_Controller* SPController;

	

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
	UFUNCTION(BlueprintCallable)
		void OnStopMeditation();

	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

};