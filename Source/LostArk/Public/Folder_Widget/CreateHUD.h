// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreateHUD.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UCreateHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// Create TargetCharacter spawn Location, Rotation
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	FVector SpawnLocation = FVector::ZeroVector;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	FRotator SpawnRotation = FRotator::ZeroRotator;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* JobName;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UButton* SelectJobBTN;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UButton* CreateBTN;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class APlayerBase* TargetCharacter;

	FTimerHandle TimerHandle;


	UFUNCTION()
	void ClickedJob();
	UFUNCTION()
	void Create();


	void InGame();



};
