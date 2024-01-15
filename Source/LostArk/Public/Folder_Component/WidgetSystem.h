#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WidgetSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOSTARK_API UWidgetSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWidgetSystem();

	class UUserWidget* CurrWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> LobbyHUD;

protected:
	virtual void BeginPlay() override;


public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ShowMainWidget();

		
};
