#include "../../Public/Folder_Component/InputSystem.h"
#include "../../Public/Folder_Character/CharacterBase.h"


UInputSystem::UInputSystem()
	: OwnedPlayer(nullptr)
	, PC(nullptr)
{
	UE_LOG(LogTemp, Log, TEXT("// UInputSystem"));
	OwnedPlayer = Cast<ACharacterBase>(GetOwner());
	BindAction("Jump", IE_Pressed, this, &UInputSystem::Jump);
	BindAction("Jump", IE_Released, this, &UInputSystem::StopJumping);

	BindAxis("MoveForward", this, &UInputSystem::MoveForward);
	BindAxis("MoveRight", this, &UInputSystem::MoveRight);
	BindAxis("TurnAtRate", this, &UInputSystem::TurnAtRate);
	BindAxis("LookUpAtRate", this, &UInputSystem::LookUpAtRate);
}

void UInputSystem::Jump()
{
	if (OwnedPlayer)
	{
		OwnedPlayer->Jump();
		OwnedPlayer->Skill(ESkill::BaseAttack);
	}
}

void UInputSystem::StopJumping()
{
	if (OwnedPlayer)
	{
		OwnedPlayer->StopJumping();
	}
}

void UInputSystem::MoveForward(float Value)
{
	if (OwnedPlayer)
	{
		OwnedPlayer->MoveForward(Value);
	}
}


void UInputSystem::MoveRight(float Value)
{
	if (OwnedPlayer)
	{
		OwnedPlayer->MoveRight(Value);
	}
}


void UInputSystem::TurnAtRate(float Rate)
{
	if (OwnedPlayer)
	{
		OwnedPlayer->TurnAtRate(Rate);
	}
}

void UInputSystem::LookUpAtRate(float Rate)
{
	if (OwnedPlayer)
	{
		OwnedPlayer->LookUpAtRate(Rate);
	}
}
