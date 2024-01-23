// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Folder_Character/CharacterBase.h"
#include "GI_LostArk.generated.h"

UENUM(BlueprintType)
enum class EScene : uint8
{
	NONE,
	Lobby,
	Create,
	Shop,
	InGame,

	END,
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

public:
	UGI_LostArk();

	UDataTable* JobMeshTable;

	FCharaterInfo* GetPlayerInfo() { return PlayerInfo; }
	void SetPlayerInfo(FCharaterInfo* _PlayerInfo) { PlayerInfo = _PlayerInfo; }
	EScene GetCurrScene() { return currScene; }
	void SetCurrScene(EScene _CurrScene) { currScene = _CurrScene; }

	void ChangeLevel(float _CameraTime, const FName& _LevelName);
	void StartLevel(float _CameraTime);


};
