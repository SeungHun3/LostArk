#include "Folder_Widget/ExitBTN.h"
#include "Components/CanvasPanel.h"
#include "Blueprint/UserWidget.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Component/InputSystem.h"

void UExitBTN::ExitWidget()
{
    Parent->RemoveFromParent();
	APlayerBase* player = Cast<APlayerBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player)
	{
		player->EnableInput(player->OwingController);
		player->SetMovement(true);
	}
}
