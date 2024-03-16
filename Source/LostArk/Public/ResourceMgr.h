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
UENUM(BlueprintType)
enum class EMonster : uint8
{
	None,
	Oak,
	Wolf,
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
	//GM Pawn 설정: Blueprint경로
	FString GetInGamePlayerBP_Path(EJob _EJob);
	FString GetLobbyPlayerBP_Path();
	FString GetCreatePlayerBP_Path();

	FString GetCreateTargetBP_Path();

	//메시 경로
	USkeletalMesh* GetPlayerMesh(EJob _EJob);
	USkeletalMesh* GetMonsterMesh(EMonster _Type);
	USkeletalMesh* OakMesh;
	USkeletalMesh* WolfMesh;

	FString GetSkill_QPath(EJob _EJob);
	FString GetSkill_WPath(EJob _EJob);
	FString GetSkill_EPath(EJob _EJob);
	FString GetSkill_RPath(EJob _EJob);



private:
	ResourceMgr();
	~ResourceMgr();
};

UUserWidget* GetMainHUD(UUserWidget* _CurWidget);