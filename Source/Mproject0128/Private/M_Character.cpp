#include "..\Public\M_Character.h"


#include "GameFramework/SpringArmComponent.h"//��������ɱۿ���
#include "GameFramework/CharacterMovementComponent.h"//��ɫ�ƶ�����

#include "Camera/CameraComponent.h"//�����

#include "Components/InputComponent.h"//�������
#include "Components/SkeletalMeshComponent.h"//�������

#include "Kismet/GameplayStatics.h"//��̬���߰���ʧȥ�����ÿ��ܻ�������󣨾���δ�˽⣩
#include "Engine.h"


AM_Character::AM_Character()
{  
	//�����������Ҫ�������������������õ�ָ�룻
	//CharacterMesh->SetSimulatePhysics(true);//����ģ��ǳ��������ܣ�����Ҫ��ʱ��Ҫ��������������ʱ������Ч�����Կ�����


	//�������������͵��ɱ�
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->SetupAttachment(GetMesh());
	CameraArm->bUsePawnControlRotation = true;

	// Create a CameraComponent	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);
	Camera->RelativeLocation = FVector(0, 0, BaseEyeHeight); // Position the camera
	CameraArm->bUsePawnControlRotation = false;

	//���������������������
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	//RootComponent = CharacterMesh;//��һ�������Ľ�������Ϊ�������Mesh�����ڸ�����ϻ�������������ϣ�

	//��������ê�����
	MagicSlot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EffectSlot"));
	MagicSlot->CastShadow = false;
	//MagicSlotComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	//MagicSlotComponent->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	

	//C++������ͼ����1����ȡ�����ͼ�������,���ͺͶ���
	static ConstructorHelpers::FClassFinder<AActor> BP_ActorMatch(TEXT("Blueprint'/Game/BluePrint/Skill/BPM_MagicBullet.BPM_MagicBullet_C'"));
	if (BP_ActorMatch.Succeeded()) { MatchBPMgaicActor = BP_ActorMatch.Class; }

	static ConstructorHelpers::FObjectFinder<UClass> BP_ClassFinder(TEXT("Blueprint'/Game/BluePrint/Skill/BPM_MagicBullet.BPM_MagicBullet_C'"));
	if (BP_ClassFinder.Object) { UClass* bpClass = BP_ClassFinder.Object; }

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
	PlayerInputComponent->BindAction("Meditation", IE_Released, this, &AM_Character::OnStopMeditation);
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
	if (MatchBPMgaicActor)
	{
		//��ȡ������������
		FVector MuzzleLocation = MagicSlot->GetComponentLocation();
		FRotator MuzzleRotation = Controller->GetControlRotation();
		GetWorld()->SpawnActor<AM_MagicBullet>(MatchBPMgaicActor,MuzzleLocation, MuzzleRotation);
		
		if (SPController->SPState) 
		{
			SPController->SPState->OnCostMana(100); 
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("fire Got! Cost Mana Character Right"));
		}

		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("fireʹ�óɹ�"));

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
	if (SPController->SPState)
	{
		SPController->SPState->SetIsMeditation(true);
		SPController->SPState->OnRecoverMana(10);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("ManaRecover!Character right!"));
	}

}

void AM_Character::OnStopMeditation()
{
	if (SPController->SPState)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("got SPController->SPState"));
		SPController->SPState->SetIsMeditation(false);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("ManaCostStop"));
	}
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("havent cost"));
}

void AM_Character::BeginPlay()
{
	Super::BeginPlay();

	//���������ָ��Ϊ��,�������
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}
/*
float AM_Character::GetAxisValue_MoveForward()
{
	return GetAxisValue("MoveForward");
}

float AM_Character::GetAxisValue_MoveRight()
{
	return 0.0f;
}
*/

