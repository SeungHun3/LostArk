#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DungeonWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UDungeonWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UImage* DungeonImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* EnterBTN;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UExitBTN* ExitDungeonBTN;


	UFUNCTION()
	void Enter();

};
