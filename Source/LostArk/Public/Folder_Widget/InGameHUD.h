// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UInGameHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	// Widget
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* MiniMapWidget;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* QuestWidget;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UStatusWidget* StatusWidget;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class ULevelWidget* LevelWidget;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* ToolBarWidget;


	//// Toolbar
	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	//class UButton* ShopBTN;
	//
	
	//
	//
	//UFUNCTION()
	//void ShopToggle();
};
