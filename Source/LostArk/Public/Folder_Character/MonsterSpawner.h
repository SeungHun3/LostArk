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
	FActorSpawnParameters MonsterSpawnParam;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = MonsterLocation )
	TMap<FName, class ATargetPoint*> SpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AMonsterBase> WolfClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AMonsterBase> OakClass;
	
	UClass* SpawnClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeRate;


	int CheckMonsterCount(const FName& Tag);
	void Spawn(const FName& Tag);

private:
	const struct FMonsterName
	{
	public:
		const FName& Wolf = "Wolf";
		const FName& Oak = "Oak";
	} MonsterName;

};
