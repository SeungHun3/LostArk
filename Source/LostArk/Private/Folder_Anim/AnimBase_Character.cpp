#include "Folder_Anim/AnimBase_Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Folder_Character/Player/PlayerBase.h"

UAnimBase_Character::UAnimBase_Character()
{
	IsInAir = false;
	Speed = 0.f;
	BaseCombo = 0;
	Skill = ESkill::NONE;
	BaseOpen = false;
	Pressed_SkillBase = false;
}

void UAnimBase_Character::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	Player = Cast<APlayerBase>(TryGetPawnOwner());
	if (Player)
	{
		Player->Delegate_Skill_Base.AddDynamic(this, &UAnimBase_Character::Skill_Base);
		Player->Delegate_Skill_Q.AddDynamic(this, &UAnimBase_Character::Skill_Q);

	}
}




void UAnimBase_Character::ChangeState(ESkill _type)
{

	switch (_type)
	{
	case ESkill::NONE:
		BaseCombo = 0;
		Skill = ESkill::NONE;
		if (Player)
		{
			Player->GetMovementComponent()->SetActive(true);
		}
		break;

	case ESkill::Base:

		if (BaseCombo == 0)
		{
			BaseCombo = 1;
		}
		else if (BaseCombo == 1)
		{
			BaseCombo = 2;
		}
		else if (BaseCombo == 2)
		{
			ChangeState(ESkill::NONE);
		}
		break;

	case ESkill::Skill_Q:

		break;

	case ESkill::Skill_W:
		break;

	case ESkill::END:

		break;
	default:
		break;
	}
}


void UAnimBase_Character::NativeUpdateAnimation(float DeltaSeconds)
{
	APawn* Owner = TryGetPawnOwner();
	if (Owner)
	{
		IsInAir = Owner->GetMovementComponent()->IsFalling();
		Speed = Owner->GetVelocity().Length();
	}
	
}

void UAnimBase_Character::Skill_Base()
{
	if (BaseOpen)
	{
		Pressed_SkillBase = true;
	}
	Skill = ESkill::Base;
}

void UAnimBase_Character::AnimNotify_SKillBase_Open()
{
	BaseOpen = true;
}

void UAnimBase_Character::AnimNotify_SKillBase_StartCombo()
{

	if (BaseOpen && Pressed_SkillBase)
	{
		BaseOpen = false;
		Pressed_SkillBase = false;
		ChangeState(ESkill::Base);
	}
	else
	{
		BaseOpen = false;
		Pressed_SkillBase = false;
		ChangeState(ESkill::NONE);
	}
}

void UAnimBase_Character::Skill_Q()
{

}

void UAnimBase_Character::Skill_W()
{
}

