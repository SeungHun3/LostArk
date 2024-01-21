#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ExitBTN.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UExitBTN : public UButton
{
	GENERATED_BODY()
public:
	//virtual void PostLoad() override;

	class UCanvasPanel* ParentWidget;

	UFUNCTION()
	void ExitWidget();

	UCanvasPanel* FindParent(UPanelWidget* Child, int FindCount);
};
