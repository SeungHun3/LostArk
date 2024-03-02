#include "Folder_Anim/AnimBase_Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Folder_Character/CharacterBase.h"

UAnimBase_Character::UAnimBase_Character()
{
	Player = nullptr;
	IsInAir = false;
	Speed = 0.f;
	Skill = ESkill::NONE;
}

void UAnimBase_Character::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	Player = Cast<ACharacterBase>(TryGetPawnOwner());
}




void UAnimBase_Character::ChangeState(ESkill eSkill)
{

	switch (eSkill)
	{
	case ESkill::NONE:
		Skill = ESkill::NONE;
		StateNone();
		break;

	case ESkill::Base:
		Skill = ESkill::Base;
		StateBaseAttack();
		break;
	}
}


void UAnimBase_Character::NativeUpdateAnimation(float DeltaSeconds)
{
	//Super::NativeUpdateAnimation(DeltaSeconds);
	APawn* Owner = TryGetPawnOwner();
	if (Owner)
	{
		IsInAir = Owner->GetMovementComponent()->IsFalling();
		Speed = Owner->GetVelocity().Size();
	}
}

void UAnimBase_Character::StateBaseAttack()
{
	AnimNotify_BaseAttackEnd();// юс╫ц
}

void UAnimBase_Character::StateNone()
{
	if (Player)
	{
		Player->SetMovement(true);
	}
}

void UAnimBase_Character::AnimNotify_BaseAttackEnd()
{
	ChangeState(ESkill::NONE);
}
