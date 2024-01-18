#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterSpawner.generated.h"

UCLASS()
class LOSTARK_API AMonsterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AMonsterSpawner();

protected:
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = MonsterLocation )
	TMap<FName, class ATargetPoint*> SpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AMonsterBase> MonsterClass;
	
	UClass* MonsterBlueprintClass;
	int CheckMonsterCount(const FName& Tag);
	void Spawn();


};
