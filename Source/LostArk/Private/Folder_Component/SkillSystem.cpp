#include "Folder_Component/SkillSystem.h"

USkillSystem::USkillSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void USkillSystem::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USkillSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

