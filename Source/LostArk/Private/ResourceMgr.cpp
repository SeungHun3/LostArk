#include "ResourceMgr.h"

ResourceMgr::ResourceMgr()
{
	UE_LOG(LogTemp, Log, TEXT("//ResourceMgr"));
}

ResourceMgr::~ResourceMgr()
{
}




FString ResourceMgr::GetInGamePlayerRes(EJob _EJob)
{
	FString PlayerRes = "/Game/Character/Player/BP_PlayerBase";
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
	return FString("/Game/Character/Player/BP_PlayerBase");
}

FString ResourceMgr::GetCreatePlayerRes()
{
	return FString("/Game/Character/Player/BP_PlayerBase");
}

FString ResourceMgr::GetCreateTargetRes()
{
	return FString("/Game/Character/BP_CreateTarget");
}
