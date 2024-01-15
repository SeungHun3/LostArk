#include "Folder_Component/InputSystem.h"
#include "Folder_Character/Player/PlayerBase.h"


UInputSystem::UInputSystem()
	: OwnedPlayer(nullptr)
	, PC(nullptr)
{
	UE_LOG(LogTemp, Log, TEXT("// UInputSystem"));
	OwnedPlayer = Cast<APlayerBase>(GetOwner());
	BindAction("Jump", IE_Pressed, this, &UInputSystem::Jump);
	BindAction("Jump", IE_Released, this, &UInputSystem::StopJumping);
}

void UInputSystem::Jump()
{
	if (OwnedPlayer)
	{
		OwnedPlayer->Jump();
		OwnedPlayer->Skill(ESkill::Skill_01);
	}
}

void UInputSystem::StopJumping()
{
	if (OwnedPlayer)
	{
		OwnedPlayer->StopJumping();
	}
}
