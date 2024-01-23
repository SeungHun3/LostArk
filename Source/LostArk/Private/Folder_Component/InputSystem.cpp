#include "Folder_Component/InputSystem.h"
#include "Framework/Commands/InputChord.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "Folder_Character/PC_Base.h"

UInputSystem::UInputSystem()
	: OwnedPlayer(nullptr)
	, PC(nullptr)
{
	UE_LOG(LogTemp, Log, TEXT("// UInputSystem"));
	OwnedPlayer = Cast<APlayerBase>(GetOwner());
	BindAction("Jump", IE_Pressed, this, &UInputSystem::Jump);
	BindAction("Jump", IE_Released, this, &UInputSystem::StopJumping);

	const FInputChord KeyChord(EKeys::AnyKey);

	FInputKeyBinding KB = FInputKeyBinding(KeyChord, EInputEvent::IE_Pressed);
	KB.KeyDelegate.BindDelegate(this, &UInputSystem::OnSkillPressed);
	KB.bConsumeInput = false;
	KeyBindings.Emplace(MoveTemp(KB));
	
	KB = FInputKeyBinding(KeyChord, EInputEvent::IE_Released);
	KB.KeyDelegate.BindDelegate(this, &UInputSystem::OnSkillReleased);
	KB.bConsumeInput = false;
	KeyBindings.Emplace(MoveTemp(KB));
}

void UInputSystem::Jump()
{
	if (OwnedPlayer)
	{
		OwnedPlayer->Jump();
	}
}

void UInputSystem::StopJumping()
{
	if (OwnedPlayer)
	{
		OwnedPlayer->StopJumping();
	}
}

void UInputSystem::OnSkillPressed(FKey InKey)
{
	if (InKey.ToString() == "LeftMouseButton")
	{
		OwnedPlayer->Skill(ESkill::Base);
	}
	else if (InKey.ToString() == "RightMouseButton")
	{
		OwnedPlayer->Move();
	}

	// num1 num2.. 및 마우스 입력 제외
	if (InKey.ToString().Len() > 2)
		return;

	char Key = InKey.ToString()[0];
	int asciiKey = static_cast<int>(Key);
	// Q: 81, W: 87, E: 69, R: 82
	switch (asciiKey)
	{	
	case 81: // Q
		OwnedPlayer->Skill(ESkill::Skill_Q);
		UE_LOG(LogTemp, Log, TEXT("//key : %s,  %c %d"), *InKey.ToString(), Key, asciiKey);
		break;

	case 87: // W
		OwnedPlayer->Skill(ESkill::Skill_W);
		UE_LOG(LogTemp, Log, TEXT("//key : %s,  %c %d"), *InKey.ToString(), Key, asciiKey);
		break;

	case 69: // E
		break;

	case 82: // R
		break;
	}

	//UE_LOG(LogTemp, Log, TEXT("//key : %s,  %c %d"), *InKey.ToString(), Key, asciiKey);
}

void UInputSystem::OnSkillReleased(FKey InKey)
{
}

