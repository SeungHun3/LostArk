// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
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
struct FCharaterMesh : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMesh* Mesh;
};


UCLASS()
class LOSTARK_API UGI_LostArk : public UGameInstance
{
	GENERATED_BODY()
private:
	EScene currScene;

public:
	UGI_LostArk();

	UDataTable* JobMesh;


	EScene GetCurrScene() { return currScene; }
	void SetCurrScene(EScene _CurrScene) { currScene = _CurrScene; }

};
