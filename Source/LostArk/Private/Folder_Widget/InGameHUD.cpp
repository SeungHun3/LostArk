#include "Folder_Widget/InGameHUD.h"

#include "GI_LostArk.h"

void UInGameHUD::NativeConstruct()
{
	UE_LOG(LogTemp, Log, TEXT("//UInGameHUD"));
	Super::NativeConstruct();

	UGI_LostArk* GI = Cast<UGI_LostArk>(GetGameInstance());
	if (GI)
	{
		GI->StartLevel(3.f);
	}
	//
	//ShopBTN->OnClicked.AddDynamic(this, &UInGameHUD::ShopToggle);
}
