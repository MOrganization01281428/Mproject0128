#pragma once

#include "CoreMinimal.h"//���������ļ���δ�������ܻ����δ֪����
#include "GameFramework/Character.h"//�̳н�ɫ��

#include "M_MagicBullet.h"
#include "M_Controller.h"

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
//�������ʼ��
	AM_Character();
	virtual void BeginPlay() override;


//����ͨ��

	TSubclassOf<AActor> MatchBPMgaicActor;

	class AM_Controller* SPController;


//�������
	UPROPERTY(EditAnywhere, Category = "Mesh")
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = "Camera")
		USpringArmComponent* CameraArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Magic")
		UStaticMeshComponent* MagicSlotComponent;

//��Ϊ��
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
	UFUNCTION(BlueprintCallable, Category = "Control")
		bool IsDead();
	UFUNCTION(BlueprintCallable, Category = "Control")
		void AcceptDamage(int DamageVal);

};