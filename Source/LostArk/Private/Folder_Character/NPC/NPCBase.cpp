#include "Folder_Character/NPC/NPCBase.h"
#include "Components/CapsuleComponent.h"
#include "Folder_Widget/Folder_InGame/ShopWidget.h"
ANPCBase::ANPCBase()
{
	
	GetCapsuleComponent()->SetCollisionProfileName(FName("NPC"));
	OnClicked.AddDynamic(this, &ANPCBase::ClickedActor);
}


void ANPCBase::ClickedActor(AActor* ClickedActor, FKey ButtonClicked)
{
	UUserWidget* pShopWidget = CreateWidget<UUserWidget>(GetWorld(), ShopWidget);
	if (pShopWidget)
	{
		pShopWidget->AddToViewport();
	}
	UE_LOG(LogTemp, Log, TEXT("//Create ShopWidget"));
}
