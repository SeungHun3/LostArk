#include "Folder_Character/NPC/NPCBase.h"
#include "Folder_Widget/Folder_InGame/ShopWidget.h"
ANPCBase::ANPCBase()
	:IsOpenWidget(false)
{
}

void ANPCBase::Clicked()
{
	IsOpenWidget = true;
	CreateWidget<UUserWidget>(GetWorld(), ShopWidget);

}
