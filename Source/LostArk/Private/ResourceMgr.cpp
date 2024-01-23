#include "ResourceMgr.h"
#include "Blueprint/UserWidget.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "Folder_Component/WidgetSystem.h"

ResourceMgr::ResourceMgr()
{
	UE_LOG(LogTemp, Log, TEXT("//ResourceMgr"));
}

ResourceMgr::~ResourceMgr()
{
}




FString ResourceMgr::GetInGamePlayerRes(EJob _EJob)
{
	FString PlayerRes = "/Game/Character/Player/BP_InGamePlayer";
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::Monster:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return PlayerRes;
}

FString ResourceMgr::GetLobbyPlayerRes()
{
	return FString("/Game/Character/Player/BP_LobbyPlayer");
}

FString ResourceMgr::GetCreatePlayerRes()
{
	return FString("/Game/Character/Player/BP_CreatePlayer");
}

FString ResourceMgr::GetCreateTargetRes()
{
	return FString("/Game/Character/BP_CreateTarget");
}

FString ResourceMgr::GetSkill_QRes(EJob _EJob)
{
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::Monster:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_Q");
}

FString ResourceMgr::GetSkill_WRes(EJob _EJob)
{
	switch (EJob::None)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::Monster:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_W");
}

FString ResourceMgr::GetSkill_ERes(EJob _EJob)
{
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::Monster:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_E");
}

FString ResourceMgr::GetSkill_RRes(EJob _EJob)
{
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::Monster:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_R");
}




UUserWidget* GetMainHUD(UUserWidget* _CurWidget)
{
	APlayerBase* Player = Cast<APlayerBase>(_CurWidget->GetOwningPlayerPawn());
	if (!Player)
		return nullptr;

	return Player->WidgetSystem->CurrHUD;
}