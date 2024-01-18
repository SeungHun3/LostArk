#include "Folder_Character/MonsterSpawner.h"
#include "Folder_Character/Monster/MonsterBase.h"
#include "Engine/TargetPoint.h"
#include "EngineUtils.h"

AMonsterSpawner::AMonsterSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn(); 
	
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

void AMonsterSpawner::Spawn()
{
	FActorSpawnParameters MonsterSpawnParam;
	MonsterSpawnParam.Owner = this;
	MonsterSpawnParam.Instigator = GetInstigator();
	MonsterSpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	for (const auto& SpawnTarget : SpawnLocation)
	{
		FName TagName = SpawnTarget.Key;
		FString ss = TagName.ToString();
		if(TagName == "Oak")
		{
			int MonsterCount = CheckMonsterCount(TagName);
			if (MonsterCount <= 10)
			{
				AActor* SpawnedMonster = GetWorld()->SpawnActor<AActor>(MonsterClass, FVector(0.f, 0.f, 0.f), FRotator(0.f), MonsterSpawnParam);
				if (SpawnedMonster)
				{
					UE_LOG(LogTemp, Log, TEXT("// Spawn "));
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("// Spawn not "));
				}
			}
		}
		else if(TagName == "Wolf")
		{

		}

	}
}


