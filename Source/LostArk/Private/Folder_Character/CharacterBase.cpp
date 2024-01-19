#include "Folder_Character/CharacterBase.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Folder_Component/SkillSystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

#include "Folder_Anim/AnimBase_Character.h"

ACharacterBase::ACharacterBase()
	: TotalInfo{}, Job(EJob::None)
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
	UE_LOG(LogTemp, Log, TEXT("//ACharacterBase"));
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

bool ACharacterBase::Skill_Base()
{
	if (AnimStateCheck(ESkill::NONE) || AnimStateCheck(ESkill::Base))
	{
		GetCharacterMovement()->SetActive(false);
		UE_LOG(LogTemp, Log, TEXT("// ACharacterBase: Skill_Base"));
		return true;
	}
	return false;
}

bool ACharacterBase::Skill_Q()
{
	if (!AnimStateCheck(ESkill::NONE))
		return false;

	GetCharacterMovement()->SetActive(false);
	UE_LOG(LogTemp, Log, TEXT("// ACharacterBase: Skill_Q"));
	return true;
}

bool ACharacterBase::Skill_W()
{
	if (!AnimStateCheck(ESkill::NONE))
		return false;

	GetCharacterMovement()->SetActive(false);
	UE_LOG(LogTemp, Log, TEXT("// ACharacterBase: Skill_W"));
	return true;
}

bool ACharacterBase::AnimStateCheck(ESkill _type)
{
	UAnimBase_Character* AnimInstance = Cast<UAnimBase_Character>(GetMesh()->GetAnimInstance());
	if (AnimInstance && AnimInstance->Skill == _type)
	{
		return true;
	}
	return false;
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
