#include "Folder_Widget/ExitBTN.h"
#include "Components/CanvasPanel.h"
#include "Blueprint/UserWidget.h"

void UExitBTN::ExitWidget()
{
    for (auto pWidget : Parent)
    {
        pWidget->RemoveFromParent();
    }
}
