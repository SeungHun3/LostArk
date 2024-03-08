#include "Folder_Widget/Folder_InGame/InventoryWidget.h"
#include "Folder_Widget/Folder_InGame/InventorySlotWidet.h"
#include "Components/UniformGridPanel.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Folder_Widget/ExitBTN.h"

#define SLOTSIZE_X 100
#define SLOTSIZE_Y 100

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!SlotClass)
		return;
	
	int row = 4;
	int column = 7;
	FVector2D GridSize = FVector2D(SLOTSIZE_X * column, SLOTSIZE_Y * row);
	UWidgetLayoutLibrary::SlotAsCanvasSlot(SlotUniform)->SetSize(GridSize);
	UWidgetLayoutLibrary::SlotAsCanvasSlot(Uniform_Bg)->SetSize(GridSize);
	for (int i = 0; i < row * column; i++)
	{
		SlotUniform->AddChildToUniformGrid(CreateWidget<UUserWidget>(GetWorld(), SlotClass), i % row, i / row);
	}
	ExitInventoryBTN->BindWidget(this);
	DragBTN->OnPressed.AddDynamic(this, &UInventoryWidget::DragPressed);
	DragBTN->OnReleased.AddDynamic(this, &UInventoryWidget::DragReleased);
}

void UInventoryWidget::DragPressed()
{
	FVector2D mousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	FVector2D canvasPosition = UWidgetLayoutLibrary::SlotAsCanvasSlot(InvenCanvas)->GetPosition();
	Mouse_Relative = mousePosition - canvasPosition;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UInventoryWidget::UpdateMousePosition, 0.01f, true);
}

void UInventoryWidget::DragReleased()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void UInventoryWidget::UpdateMousePosition()
{
	FVector2D mousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	UWidgetLayoutLibrary::SlotAsCanvasSlot(InvenCanvas)->SetPosition(mousePosition - Mouse_Relative);
	
}
