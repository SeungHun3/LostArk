#include "Folder_Character/MonsterSpawner.h"
#include "Folder_Character/Monster/MonsterBase.h"
#include "Engine/TargetPoint.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

#define MONSTERCOUNT 10

AMonsterSpawner::AMonsterSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	SpawnClass = nullptr;
	TimeRate = 10.f;
	MonsterSpawnParam.Owner = this;
	MonsterSpawnParam.Instigator = GetInstigator();
	MonsterSpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	UE_LOG(LogTemp, Log, TEXT("// AMonsterSpawner"));
	
}

void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();

	FTimerDelegate TimerDelegate;
	FTimerHandle TimerHandle;
	TimerDelegate.BindLambda([this]()
		{
			UE_LOG(LogTemp, Log, TEXT("// AMonsterSpawner : Timer"));
			Spawn(MonsterName.Oak);
			Spawn(MonsterName.Wolf);
		});
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, TimeRate, true);
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
	SpawnClass = nullptr;

	if (Tag == MonsterName.Oak)
	{
		SpawnClass = OakClass;
	}
	else if (Tag == MonsterName.Wolf)
	{
		SpawnClass = WolfClass;
	}
	ATargetPoint* FoundTargetTag = *SpawnLocation.Find(Tag);

	if (!FoundTargetTag || !SpawnClass)
		return;


	FVector TargetLocation = FoundTargetTag->GetRootComponent()->GetComponentLocation();
	int WorldMonsters = CheckMonsterCount(Tag);
	if (WorldMonsters <= MONSTERCOUNT)
	{
		for (int i = 0; i < MONSTERCOUNT - WorldMonsters; i++)
		{
			GetWorld()->SpawnActor<AActor>(SpawnClass, TargetLocation, FRotator(0.f), MonsterSpawnParam);
		}
	}
}


