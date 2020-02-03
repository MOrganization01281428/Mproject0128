#include "..\Public\M_Character.h"


#include "GameFramework/SpringArmComponent.h"//��������ɱۿ���
#include "GameFramework/CharacterMovementComponent.h"//��ɫ�ƶ�����

#include "Camera/CameraComponent.h"//�����

#include "Components/InputComponent.h"//�������
#include "Components/SkeletalMeshComponent.h"//�������

#include "Kismet/GameplayStatics.h"//��̬���߰���ʧȥ�����ÿ��ܻ�������󣨾���δ�˽⣩
#include "Engine.h"


AM_Character::AM_Character()
{  //���������������������
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	RootComponent = CharacterMesh;
	//CharacterMesh->SetSimulatePhysics(true);//����ģ��ǳ��������ܣ�����Ҫ��ʱ��Ҫ��������������ʱ������Ч�����Կ�����


	//�������������͵��ɱ�
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);

	//��������ê�����
	MagicSlotComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EffectSlot"));
	MagicSlotComponent->CastShadow = false;
	//MagicSlotComponent->SetUpAttachment(RootComponent);

}

void AM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) 
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	//�󶨺���
	PlayerInputComponent->BindAxis("MoveForward", this, &AM_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AM_Character::MoveLeft);
	PlayerInputComponent->BindAxis("LookUp", this, &AM_Character::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AM_Character::LookRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AM_Character::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AM_Character::OnStopJump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AM_Character::Fire);
	PlayerInputComponent->BindAction("Meditation", IE_Pressed, this, &AM_Character::OnStartMeditation);
	//PlayerInputComponent->BindAction("Meditation", IE_Released, this, &AM_Character::OnStopMeditation);
}

//����������Ϊ�����飺
void AM_Character::MoveForward(float value)
{
	if (value != 0.f && Controller) {
		const FRotator Rotation = Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AM_Character::MoveLeft(float value)
{
	if (value != 0.f && Controller) {
		const FQuat Rotation = GetActorQuat();
		FVector Direction = FQuatRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void AM_Character::LookUp(float value)
{
	if (value != 0 && Controller)
	{
		AddControllerPitchInput(value);
	}
}

void AM_Character::LookRight(float value)
{
	if (value != 0 && Controller)
	{
		AddControllerYawInput(value);
	}
}

void AM_Character::OnStartJump()
{
	bPressedJump = true;
}

void AM_Character::OnStopJump()
{
	bPressedJump = false;
	StopJumping();
}

void AM_Character::Fire()
{
	if (MagicBulletClass)
	{
		//��ȡ������������
		FVector MuzzleLocation = MagicSlotComponent->GetComponentLocation();
		FRotator MuzzleRotation = Controller->GetControlRotation();
		GetWorld()->SpawnActor<AActor>(MagicBulletClass, MuzzleLocation, MuzzleRotation);
		//������ײ->��Ϣ//Ҳ���Բ����ã����actor���������ˣ�
		//Set Spawn Collision Handling Override
		//FActorSpawnParameters ActorSpawnParams;
		//ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		//����һ��Actor�����ʵ��
		// spawn the projectile at the muzzle
		//GetWorld()->SpawnActor<AFPSProjectile>(MagicBulletClass, MuzzleLocation, MuzzleRotation, ActorSpawnParams);
	}

}

void AM_Character::OnStartMeditation()
{
}


