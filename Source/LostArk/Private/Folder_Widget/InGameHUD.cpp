#include "Folder_Widget/InGameHUD.h"


void UInGameHUD::NativeConstruct()
{
	UE_LOG(LogTemp, Log, TEXT("//UInGameHUD"));
	Super::NativeConstruct();

	
	//
	//ShopBTN->OnClicked.AddDynamic(this, &UInGameHUD::ShopToggle);
}
