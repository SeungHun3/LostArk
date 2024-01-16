#include "Folder_Widget/Folder_InGame/LevelWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "Folder_Character/Player/PlayerBase.h"


void ULevelWidget::NativeConstruct()
{	
	Super::NativeConstruct();
	APlayerBase* Player = Cast<APlayerBase>(GetOwningPlayerPawn());
	if (!Player)
		return;
	LevelText->SetText(FText::AsNumber(Player->TotalInfo.GetLevel()));
	ExperienceBar->SetPercent(0.f); 
	//ExperienceBar->SetPercent(0.5f);
}
