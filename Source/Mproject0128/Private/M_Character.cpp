#include "..\Public\M_Character.h"


#include "GameFramework/SpringArmComponent.h"//��������ɱۿ���
#include "GameFramework/CharacterMovementComponent.h"//��ɫ�ƶ�����

#include "Camera/CameraComponent.h"//�����

#include "Components/InputComponent.h"//�������
#include "Components/SkeletalMeshComponent.h"//�������

#include "Kismet/GameplayStatics.h"//��̬���߰���ʧȥ�����ÿ��ܻ�������󣨾���δ�˽⣩
#include "Engine.h"


//�ܽ᣺
/*
1.�������-ʵ���������������á�
2.��������-ʵ�ֻ���������
3.��ȡ���õ�ָ�룬��������C++����ͼ������ݡ�
����������
	ʵ������������������
	��ȡ��Ҫ��ͼ������ã��緢��Ĳ��Թ���
BeginPlay
	��ȡControllerָ��
��������ʵ�֣��ƶ���Fire��Meditation��
	Movement Baseϵ��
	Fireϵ��
	Meditationϵ��

��Character���������ͨ���嵥��
ͨ�����ò�ѯ�� SP~��SPController��
ͨ�Žӿڣ����ޣ�

ͨ�����ݣ�
��ʹ�ü���ʱ���޸�PlayerState�еı���������ֵ��ħ��ֵ��
������ɡ��ڴ��������ַ�洢
������ɡ��������˺����Ӵ����˺��¼�
�����ڡ��ܴ浵ϵͳ�뱳��ϵͳ��Buff

*/
AM_Character::AM_Character()
{  
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
	MagicSlotComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EffectSlot"));
	MagicSlotComponent->CastShadow = false;
	//MagicSlotComponent->SetUpAttachment(GetCapsuleComponent());
	

	//��ȡ�����ͼ�������,���ͺͶ���
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
	if (MatchBPMgaicActor)
	{
		//��ȡ������������
		FVector MuzzleLocation = MagicSlotComponent->GetComponentLocation();
		FRotator MuzzleRotation = Controller->GetControlRotation();
		GetWorld()->SpawnActor<AM_MagicBullet>(MatchBPMgaicActor,MuzzleLocation, MuzzleRotation);
<<<<<<< Updated upstream
=======
		
		if (SPController->SPState) 
		{
			SPController->SPState->OnCostMana(100); 
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("fire Cost! Mana"));
		}

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
}


=======
	IsMeditation=true;
	if (SPController->SPState && IsMeditation)
	{
		while (IsMeditation)
		{
			SPController->SPState->OnRecoverMana(10);
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT("[OnStartMeditation]Manarecover!:"));
		}
		
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("[OnStartMeditation]ManaRecover Wrong!"));
	}

}

void AM_Character::OnStopMeditation()
{
	IsMeditation = false;

}

void AM_Character::BeginPlay()
{
	Super::BeginPlay();

	//���������ָ��Ϊ��,�������
	SPController = Cast<AM_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

}
>>>>>>> Stashed changes
