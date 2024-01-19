// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UInGameBarWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* ShopBTN;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* CharacterBTN;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* DungeonBTN;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UDungeonWidget> DungeonWidget;

	UFUNCTION()
	void ToggleShop();
	UFUNCTION()
	void ToggleCharacter();
	UFUNCTION()
	void ToggleDungeon();
};
