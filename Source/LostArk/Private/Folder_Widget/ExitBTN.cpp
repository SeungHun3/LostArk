#include "Folder_Widget/ExitBTN.h"
#include "Components/CanvasPanel.h"
//void UExitBTN::PostLoad()
//{
//	Super::PostLoad();
//	OnClicked.RemoveAll(this);
//
//
//}

void UExitBTN::ExitWidget()
{
    UCanvasPanel* ParentUserWidget = FindParent(this, 50);

    if (ParentUserWidget)
    {
        for (auto Child : ParentUserWidget->GetAllChildren())
        {
            Child->RemoveFromParent();
        }
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("//No UUserWidget"));
    }
}

UCanvasPanel* UExitBTN::FindParent(UPanelWidget* Child, int FindCount)
{
    UWidget* CurrentParent = Child;

    for (int32 i = 0; i < FindCount && CurrentParent; ++i)
    {
        if (UCanvasPanel* UserWidget = Cast<UCanvasPanel>(CurrentParent))
        {
            return UserWidget;
        }
        CurrentParent = CurrentParent->GetParent();
    }

    return nullptr;
}

