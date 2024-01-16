#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EJob : uint8
{
	None,
	Warrior,
	Hunter,
	//Magician,

	Monster,
	END,
};


class LOSTARK_API ResourceMgr
{
public:
	static ResourceMgr* GetInst()
	{
		static ResourceMgr ResMgr;
		return &ResMgr;
	}

	FString GetInGamePlayerRes(EJob _EJob);
	FString GetLobbyPlayerRes();
	FString GetCreatePlayerRes();

	FString GetCreateTargetRes();

private:
	ResourceMgr();
	~ResourceMgr();
};
