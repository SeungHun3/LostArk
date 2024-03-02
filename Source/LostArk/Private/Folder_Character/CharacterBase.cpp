#include "Folder_Character/CharacterBase.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Folder_Component/SkillSystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"


ACharacterBase::ACharacterBase()
	: TotalInfo{}
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -97.f), FRotator(0.f, -90.f, 0.f));
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}



void ACharacterBase::SetMovement(bool CanMove)
{
	GetMovementComponent()->SetActive(CanMove);
}

void ACharacterBase::Skill(ESkill eSkill)
{

}
