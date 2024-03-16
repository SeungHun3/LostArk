#include "Folder_Widget/Folder_InGame/CharacterWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/Button.h"

void UCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	DragBTN->OnPressed.AddDynamic(this, &UCharacterWidget::DragPressed);
	DragBTN->OnReleased.AddDynamic(this, &UCharacterWidget::DragReleased);
}

void UCharacterWidget::DragPressed()
{
	FVector2D mousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	FVector2D canvasPosition = UWidgetLayoutLibrary::SlotAsCanvasSlot(MainCanvas)->GetPosition();
	Mouse_Relative = mousePosition - canvasPosition;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UCharacterWidget::UpdateMousePosition, 0.01f, true);
}

void UCharacterWidget::DragReleased()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void UCharacterWidget::UpdateMousePosition()
{
	FVector2D mousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	UWidgetLayoutLibrary::SlotAsCanvasSlot(MainCanvas)->SetPosition(mousePosition - Mouse_Relative);

}