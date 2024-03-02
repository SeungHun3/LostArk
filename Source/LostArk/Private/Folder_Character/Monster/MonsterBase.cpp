#include "Folder_Character/Monster/MonsterBase.h"	
#include "Folder_Widget/Folder_InGame/MonsterStatus.h"
#include "Components/WidgetComponent.h"
AMonsterBase::AMonsterBase()
{
	Tags.Add("Monster");
	StatusComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("MonsterWidget"));
	StatusComponent->SetupAttachment(RootComponent);
	StatusComponent->SetRelativeLocation(FVector(0.f, 0.f, 100.f));

}

void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	if (StatusClass)
	{
		StatusComponent->SetWidgetClass(StatusClass);
	}
	StatusWidget = Cast<UMonsterStatus>(StatusComponent->GetWidget());
	// Last Tag
	if (StatusWidget && (Tags.Num() - 1) >= 0)
	{
		StatusWidget->InitWidget(Tags[Tags.Num() - 1].ToString());
	}

}
