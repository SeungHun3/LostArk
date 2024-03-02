// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "GI_LostArk.generated.h"

UENUM(BlueprintType)
enum class EScene : uint8
{
	NONE,
	Lobby,
	Create,
	InGame,

	END,
};

USTRUCT(BlueprintType)
struct FITem
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FString, int> Weapon; // name, count

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int HP_Portion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MP_Portion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Gold;
};


// 데이터 테이블용
USTRUCT(Atomic, BlueprintType)
struct FCharaterInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EJob Job;
};




UCLASS()
class LOSTARK_API UGI_LostArk : public UGameInstance
{
	GENERATED_BODY()
private:
	EScene currScene;
	FCharaterInfo* PlayerInfo;
	FITem* Item;

public:
	UGI_LostArk();

	UDataTable* JobMeshTable;

	FCharaterInfo* GetPlayerInfo() { return PlayerInfo; }
	void SetPlayerInfo(FCharaterInfo* _PlayerInfo) { PlayerInfo = _PlayerInfo; }

	FITem* GetItem() { return Item; }
	void AddHPPortion(int _HPCount) { Item->HP_Portion = Item->HP_Portion + _HPCount; }
	void AddMPPortion(int _MPCount) { Item->MP_Portion = Item->MP_Portion + _MPCount; }
	void AddGold(int _Gold) { Item->Gold = Item->Gold + _Gold; }

	EScene GetCurrScene() { return currScene; }
	void SetCurrScene(EScene _CurrScene) { currScene = _CurrScene; }

	void ChangeLevel(float _CameraTime, const FName& _LevelName);
	void StartLevel(float _CameraTime);


};
