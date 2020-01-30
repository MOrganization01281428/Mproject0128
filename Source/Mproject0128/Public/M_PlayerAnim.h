#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "M_PlayerAnim.generated.h"

UCLASS()
class UM_PlayerAnim :public UAnimInstance
{
	GENERATED_BODY()

public:
	UM_PlayerAnim();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnim")
		float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnim")
		FRotator SpinRotator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnim")
		float Direction;
};