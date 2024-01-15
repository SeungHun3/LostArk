//#include "Folder_Character/State.h"
#include "Folder_Character/State.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Character/Player/PlayerBase.h"

AState::AState()
	:BaseProperty{}
{
}

void AState::Init(int _Level, FBaseProperty _BaseProperty)
{
	BaseProperty.totalAP = _Level * 5;
	BaseProperty.str = _BaseProperty.str;
	BaseProperty.dex = _BaseProperty.dex;
	BaseProperty.intelligence = _BaseProperty.intelligence;

	APC_Base* PC = Cast<APC_Base>(GetOwner());
	if (PC)
	{
		APlayerBase* Player = Cast<APlayerBase>(PC->GetPawn());
		if (Player)
		{
			Player->Init_Complete(BaseProperty.str, BaseProperty.dex, BaseProperty.intelligence);
		}
	}

	
}

void AState::Attacked(int _HP)
{


}

void AState::UsedSkill(int _MP, int _SP)
{

}

void AState::BeginPlay()
{
}