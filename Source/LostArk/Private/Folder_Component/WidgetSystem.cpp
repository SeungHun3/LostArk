#include "Folder_Component/WidgetSystem.h"

#include "Blueprint/UserWidget.h"
#include "Folder_Widget/LobbyHUD.h"
#include "Folder_Widget/CreateHUD.h"
#include "Folder_Widget/InGameHUD.h"
#include "GI_LostArk.h"


UWidgetSystem::UWidgetSystem()
	: CurrHUD(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UWidgetSystem::BeginPlay()
{
	Super::BeginPlay();
	ShowMainWidget();
}


void UWidgetSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UWidgetSystem::ShowMainWidget()
{
	if(CurrHUD && CurrHUD->IsInViewport())
	{
		CurrHUD->RemoveFromViewport();
	}

	if (GetOwner() && GetOwner()->GetGameInstance())
	{
		UGI_LostArk* pGI = Cast<UGI_LostArk>(GetOwner()->GetGameInstance());

		if (!pGI)
			return;


		switch (pGI->GetCurrScene())
		{
		case EScene::NONE:
			break;

		case EScene::Lobby:
			CurrHUD = CreateWidget<UUserWidget>(GetWorld(), LobbyHUD);
			if (CurrHUD)
			{
				CurrHUD->AddToViewport();
			}
			break;

		case EScene::Create:
			CurrHUD = CreateWidget<UUserWidget>(GetWorld(), CreateHUD);
			if (CurrHUD)
			{
				CurrHUD->AddToViewport();
			}
			break;
		case EScene::Shop:

			break;
		case EScene::Map01:
		case EScene::Map02:
			CurrHUD = CreateWidget<UUserWidget>(GetWorld(), InGameHUD);
			if (CurrHUD)
			{
				CurrHUD->AddToViewport();
			}
			break;

		case EScene::END:

			break;

		}
	}


}
