#include "Folder_Component/WidgetSystem.h"

#include "Blueprint/UserWidget.h"
#include "Folder_Widget/LobbyHUD.h"
#include "GI_LostArk.h"

class ALobbyHUD;

UWidgetSystem::UWidgetSystem()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UWidgetSystem::BeginPlay()
{
	Super::BeginPlay();

	
}


void UWidgetSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UWidgetSystem::ShowMainWidget()
{

	if(CurrWidget && CurrWidget->IsInViewport())
	{
		CurrWidget->RemoveFromViewport();
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

		case EScene::Scene01:
			CurrWidget = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), LobbyHUD->StaticClass());
			break;

		case EScene::Scene02:

			break;
		case EScene::Scene03:

			break;
		case EScene::Scene04:

			break;
		case EScene::END:

			break;

		default:
			break;
		}
	}


}
