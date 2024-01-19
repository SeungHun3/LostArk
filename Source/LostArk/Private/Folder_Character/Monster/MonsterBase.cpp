#include "Folder_Character/Monster/MonsterBase.h"

AMonsterBase::AMonsterBase()
{
	Job = EJob::Monster;
	Tags.Add("Monster");
	UE_LOG(LogTemp, Log, TEXT("// Monster"));
}
