#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_InGame.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API AGM_InGame : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_InGame();
	virtual void PostLogin(APlayerController* NewPlayer);

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class AMonsterSpawner* MonsterSpawner;

	void StartSpawnerTimer();
	
};
