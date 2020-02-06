#pragma once

#include "CoreMinimal.h"//���������ļ���δ�������ܻ����δ֪����
#include "GameFramework/Character.h"//�̳н�ɫ��

#include "M_MagicBullet.h"
#include "M_Controller.h"
#include "M_PlayerState.h"

#include "M_Character.generated.h"//���ɵı����ļ�������Ҫ��������

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

//��ͼ��
	//ʵ��������
	TSubclassOf<AActor> MatchBPMgaicActor;//���ָ�뽫װ�ػ�ȡ����ͼ�����ã����ǿ�ͷ�涨ֻ��ƥ����ͼ��BPMgaicActorʱʹ�ã�

//������ʵ���ࣺMagicʵ�塢����װ����Buff���µȣ�������Ȼ����Ҫʹ�õ���������ͼ���࣬��������ļ�����û�õ�
//	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
//		TSubclassOf<AM_MagicBullet> MagicBulletClass;	
//		UClass* bpCLass;
	//UPROPERTY(EditDefaultsOnly, Category = "PlayerState")
	//TSubclassOf<APlayerState> PlayerState;


//���������ࣺ���ݴ�����ң��ǽ�ɫ������
	
	class AM_Controller* SPController;

	

//�������
	UPROPERTY(EditAnywhere, Category = "Mesh")
		USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = "Magic")
		UStaticMeshComponent* MagicSlotComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
		USpringArmComponent* CameraArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* Camera;



	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


	//����������Ϊ�����飺
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

	//���Կ�����Ϊ������
	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void OnStartMeditation();
	UFUNCTION(BlueprintCallable)
		void OnStopMeditation();

	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

};