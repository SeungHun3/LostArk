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
UENUM(BlueprintType)
enum class EItemType : uint8
{
	NONE,
	Weapon,
	HP,
	MP,
};

USTRUCT(BlueprintType)
struct FItemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SerialNum;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UTexture* ItemTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Price;
};



USTRUCT(Atomic, BlueprintType)
struct FCharaterInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EJob Job;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Gold = 100;
};




UCLASS()
class LOSTARK_API UGI_LostArk : public UGameInstance
{
	GENERATED_BODY()
private:
	EScene currScene;
	FCharaterInfo* PlayerInfo;
	TMap<int, int> Items;

public:
	UGI_LostArk();
	~UGI_LostArk();
	FCharaterInfo* GetPlayerInfo() { return PlayerInfo; }
	void SetPlayerInfo(EJob Job) { PlayerInfo->Job = Job; }

	TMap<int, int> GetItem() { return Items; }
	void AddItem(int serialNum, int count)
	{ 
		if (Items.Contains(serialNum))
		{
			int* ItemCount = Items.Find(serialNum);
			*ItemCount += count;
		}
		else
		{
			Items.Add(serialNum, count);
		}
	}
	EScene GetCurrScene() { return currScene; }
	void SetCurrScene(EScene _CurrScene) { currScene = _CurrScene; }

	void ChangeLevel(float _CameraTime, const FName& _LevelName);
	void StartLevel(float _CameraTime);


};
