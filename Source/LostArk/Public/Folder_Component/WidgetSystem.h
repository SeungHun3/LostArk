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

	class UUserWidget* CurrHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ULobbyHUD> LobbyHUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UCreateHUD> CreateHUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UInGameHUD> InGameHUD;


protected:
	virtual void BeginPlay() override;


public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ShowMainWidget();

		
};
