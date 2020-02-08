#include "..\Public\M_Character.h"


#include "GameFramework/SpringArmComponent.h"//摄像机弹簧臂控制
#include "GameFramework/CharacterMovementComponent.h"//角色移动控制

#include "Camera/CameraComponent.h"//摄像机

#include "Components/InputComponent.h"//输入组件
#include "Components/SkeletalMeshComponent.h"//骨骼组件

#include "Kismet/GameplayStatics.h"//静态工具包，失去该引用可能会带来错误（具体未了解）
#include "Engine.h"


AM_Character::AM_Character()
{  
	//构建函数里，需要配置组件，创建相关引用的指针；
	//CharacterMesh->SetSimulatePhysics(true);//物理模拟非常消耗性能，不必要的时候不要开启，比如死亡时布娃娃效果可以开启；


	//创建摄像机组件和弹簧臂
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArm->SetupAttachment(GetMesh());
	CameraArm->bUsePawnControlRotation = true;

	// Create a CameraComponent	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);
	Camera->RelativeLocation = FVector(0, 0, BaseEyeHeight); // Position the camera
	CameraArm->bUsePawnControlRotation = false;

	//创建基本骨骼网格体组件
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	//RootComponent = CharacterMesh;//让一个独立的胶囊体作为根组件，Mesh悬挂在根组件上或者悬挂在相机上；

	//创建发射锚点组件
	MagicSlot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EffectSlot"));
	MagicSlot->CastShadow = false;
	//MagicSlotComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	//MagicSlotComponent->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	

	//C++调用蓝图方法1：获取相关蓝图类的引用,类型和对象；
	static ConstructorHelpers::FClassFinder<AActor> BP_ActorMatch(TEXT("Blueprint'/Game/BluePrint/Skill/BPM_MagicBullet.BPM_MagicBullet_C'"));
	if (BP_ActorMatch.Succeeded()) { MatchBPMgaicActor = BP_ActorMatch.Class; }

	static ConstructorHelpers::FObjectFinder<UClass> BP_ClassFinder(TEXT("Blueprint'/Game/BluePrint/Skill/BPM_MagicBullet.BPM_MagicBullet_C'"));
	if (BP_ClassFinder.Object) { UClass* bpClass = BP_ClassFinder.Object; }

}

void AM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) 
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	//绑定函数
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

//基础控制行为函数组：
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
		//获取生成坐标向量
		FVector MuzzleLocation = MagicSlot->GetComponentLocation();
		FRotator MuzzleRotation = Controller->GetControlRotation();
		GetWorld()->SpawnActor<AM_MagicBullet>(MatchBPMgaicActor,MuzzleLocation, MuzzleRotation);
		
		if (SPController->SPState) 
		{
			SPController->SPState->OnCostMana(100); 
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("fire Got! Cost Mana Character Right"));
		}

		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("fire使用成功"));

		//配置碰撞->信息//也可以不设置，如果actor里面设置了；
		//Set Spawn Collision Handling Override
		//FActorSpawnParameters ActorSpawnParams;
		//ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		//生成一个Actor类对象实例
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

	//如果控制器指针为空,添加引用
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

