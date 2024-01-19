#include "Folder_Character/MonsterSpawner.h"
#include "Folder_Character/Monster/MonsterBase.h"
#include "Engine/TargetPoint.h"
#include "EngineUtils.h"

#define MONSTERCOUNT 10

AMonsterSpawner::AMonsterSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	
	MonsterSpawnParam.Owner = this;
	MonsterSpawnParam.Instigator = GetInstigator();
	MonsterSpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
}

void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();

	Spawn(MonsterName.Oak);
	Spawn(MonsterName.Wolf);
}

int AMonsterSpawner::CheckMonsterCount(const FName& Tag)
{
	int TagCnt = 0;
	for (TActorIterator<AMonsterBase> ActorItr(GetWorld(), AMonsterBase::StaticClass()); ActorItr; ++ActorItr)
	{
		AMonsterBase* TargetMonster = *ActorItr;
		if (TargetMonster && TargetMonster->ActorHasTag(Tag))
		{
			TagCnt++;
		}
	}
	return TagCnt;
}

void AMonsterSpawner::Spawn(const FName& Tag)
{
	if (Tag == MonsterName.Oak)
	{
		MonsterBlueprintClass = OakClass;
	}
	else if (Tag == MonsterName.Wolf)
	{
		MonsterBlueprintClass = WolfClass;
	}
	ATargetPoint* FoundTargetTag = *SpawnLocation.Find(Tag);

	if (!FoundTargetTag || !MonsterBlueprintClass)
		return;


	FVector TargetLocation = FoundTargetTag->GetRootComponent()->GetComponentLocation();
	int WorldMonsters = CheckMonsterCount(Tag);
	if (WorldMonsters <= MONSTERCOUNT)
	{
		for (int i = 0; i < MONSTERCOUNT - WorldMonsters; i++)
		{
			AActor* SpawnedMonster = GetWorld()->SpawnActor<AActor>(MonsterBlueprintClass, TargetLocation, FRotator(0.f), MonsterSpawnParam);
			if (SpawnedMonster)
			{
				SpawnedMonster->Tags.Add("Oak");
			}
		}
	}
}


