#include "Folder_Widget/ExitBTN.h"
#include "Components/CanvasPanel.h"
#include "Blueprint/UserWidget.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Component/InputSystem.h"

void UExitBTN::ExitWidget()
{
    Parent->RemoveFromParent();
	UE_LOG(LogTemp, Log, TEXT("exit"));
	APlayerBase* player = Cast<APlayerBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player)
	{
		player->EnableInput(player->OwingController);
		player->SetMovement(true);
	}
}

void UExitBTN::BindWidget(UUserWidget* parent)
{
	Parent = parent;
	OnClicked.AddDynamic(this, &UExitBTN::ExitWidget);
	UE_LOG(LogTemp, Log, TEXT("bind"));
}
