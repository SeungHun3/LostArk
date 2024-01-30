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
	TArray<class UUserWidget*> Parent;

	UFUNCTION()
	void ExitWidget();

};
