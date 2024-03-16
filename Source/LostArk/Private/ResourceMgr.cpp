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




FString ResourceMgr::GetInGamePlayerBP_Path(EJob _EJob)
{
	FString PlayerRes = "/Game/Character/Player/BP_InGamePlayer";
	return PlayerRes;
}

FString ResourceMgr::GetLobbyPlayerBP_Path()
{
	return FString("/Game/Character/Player/BP_LobbyPlayer");
}

FString ResourceMgr::GetCreatePlayerBP_Path()
{
	return FString("/Game/Character/Player/BP_CreatePlayer");
}

FString ResourceMgr::GetCreateTargetBP_Path()
{
	return FString("/Game/Character/BP_CreateTarget");
}

USkeletalMesh* ResourceMgr::GetPlayerMesh(EJob _EJob)
{
	USkeletalMesh* Mesh = nullptr;
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		Mesh = LoadObject<USkeletalMesh>(nullptr, TEXT("/Game/Resourses/ParagonYin/Yin.Yin"));
		break;

	case EJob::Hunter:

		break;
	}

	return Mesh;
}

USkeletalMesh* ResourceMgr::GetMonsterMesh(EMonster _Type)
{
	switch (_Type)
	{
	case EMonster::None:
		break;
	case EMonster::Oak:
		OakMesh = (!OakMesh) ? LoadObject<USkeletalMesh>(nullptr, TEXT("/Game/Resourses/Goblin/SK_Epic_Goblin")) : OakMesh;
		return OakMesh;
	case EMonster::Wolf:
		WolfMesh = (!WolfMesh) ? LoadObject<USkeletalMesh>(nullptr, TEXT("/Game/Resourses/Wolf/SK_Wolf")) : WolfMesh;
		return WolfMesh;
	case EMonster::END:
		break;
	default:
		break;
	}
	return nullptr;
}

FString ResourceMgr::GetSkill_QPath(EJob _EJob)
{
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_Q");
}

FString ResourceMgr::GetSkill_WPath(EJob _EJob)
{
	switch (EJob::None)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_W");
}

FString ResourceMgr::GetSkill_EPath(EJob _EJob)
{
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
		break;
	case EJob::END:
		break;
	default:
		break;
	}

	return FString("/Game/Widget/InGame/M_Skill/M_Skill_E");
}

FString ResourceMgr::GetSkill_RPath(EJob _EJob)
{
	switch (_EJob)
	{
	case EJob::None:
		break;
	case EJob::Warrior:
		break;
	case EJob::Hunter:
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
