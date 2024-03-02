// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Folder_Character/CharacterBase.h"
#include "MonsterBase.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API AMonsterBase : public ACharacterBase
{
	GENERATED_BODY()
public:
	AMonsterBase();
	int Gold;
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UWidgetComponent* StatusComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UMonsterStatus> StatusClass;

	class UMonsterStatus* StatusWidget;

};
