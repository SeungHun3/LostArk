#include "Folder_Widget/Folder_InGame/DungeonWidget.h"
//#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Folder_Widget/ExitBTN.h"
void UDungeonWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Log, TEXT("// UDungeonWidget"));

	EnterBTN->OnClicked.AddDynamic(this, &UDungeonWidget::Enter);	
	//ExitDungeonBTN = WidgetTree->ConstructWidget<UExitBTN>(UExitBTN::StaticClass());
	ExitDungeonBTN->OnClicked.AddDynamic(ExitDungeonBTN, &UExitBTN::ExitWidget);

}

void UDungeonWidget::Enter()
{
	UE_LOG(LogTemp, Log, TEXT("// Dungeon Enter"));
}
