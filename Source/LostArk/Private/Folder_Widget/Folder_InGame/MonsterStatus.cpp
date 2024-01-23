#include "Folder_Widget/Folder_InGame/MonsterStatus.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UMonsterStatus::NativeConstruct()
{
    Super::NativeConstruct();
    Name->SetText(FText::FromString("Monster"));
    SetHP(1.f);

    //HP_Bar->AddBinding();
}

void UMonsterStatus::InitWidget(const FString& _Name)
{
	Name->SetText(FText::FromString(_Name));
}

void UMonsterStatus::SetHP(float _HPPercent)
{
	HP_Bar->SetPercent(_HPPercent);
}
