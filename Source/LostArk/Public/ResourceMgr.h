#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EJob : uint8
{
	None,
	Warrior,
	Hunter,
	//Magician,

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

	FString GetSkill_QRes(EJob _EJob);
	FString GetSkill_WRes(EJob _EJob);
	FString GetSkill_ERes(EJob _EJob);
	FString GetSkill_RRes(EJob _EJob);



private:
	ResourceMgr();
	~ResourceMgr();
};

UUserWidget* GetMainHUD(UUserWidget* _CurWidget);