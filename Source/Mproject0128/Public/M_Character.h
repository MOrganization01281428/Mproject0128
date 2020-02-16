#pragma once

#include "CoreMinimal.h"//���������ļ���δ�������ܻ����δ֪����
#include "GameFramework/Character.h"//�̳н�ɫ��
#include "M_MagicBullet.h"
#include "M_Character.generated.h"//���ɵı����ļ�������Ҫ��������

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
	AM_Character();

//��ͼ��
	//ʵ��������
	TSubclassOf<AActor> MatchBPMgaicActor;
	//���ָ�뽫װ�ػ�ȡ����ͼ�����ã����ǿ�ͷ�涨ֻ��ƥ����ͼ��BPMgaicActorʱʹ�ã�

//������ʵ���ࣺMagicʵ�塢����װ����Buff���µȣ�������Ȼ����Ҫʹ�õ���������ͼ���࣬��������ļ�����û�õ�
//	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
//		TSubclassOf<AM_MagicBullet> MagicBulletClass;	
//		UClass* bpCLass;

//���������ࣺ���ݴ�����ң��ǽ�ɫ������
	/*

	*/

//�������
	UPROPERTY(EditAnywhere, Category = "Mesh")
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = "Camera")
		USpringArmComponent* CameraArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* Camera;


	UPROPERTY(EditAnywhere, Category = "Magic")
		UStaticMeshComponent* MagicSlotComponent;


	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


	//����������Ϊ�����飺
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

	//���Կ�����Ϊ������
	UFUNCTION(BlueprintCallable,Category = "Control")
		void Fire();
	UFUNCTION(BlueprintCallable,Category = "Control")
		void OnStartMeditation();
<<<<<<< Updated upstream


	//virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;
=======
	UFUNCTION(BlueprintCallable��Category = "Control")
		void OnStopMeditation();

	virtual void BeginPlay() override;


public:
	bool IsMeditation;



};