#include "Folder_Widget/Folder_InGame/InventoryWidget.h"
#include "Folder_Widget/Folder_InGame/InventorySlotWidet.h"
#include "Components/SizeBox.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"
#include "Blueprint/WidgetLayoutLibrary.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!SlotClass)
		return;

	int sizeX = 7;
	int sizeY = 4;
	FVector2D SlotSize = UWidgetLayoutLibrary::SlotAsCanvasSlot(SlotClass.GetDefaultObject()->SizeBox)->GetSize();
	FVector2D GridSize = FVector2D(SlotSize.X * sizeX, SlotSize.Y * sizeY);
	UWidgetLayoutLibrary::SlotAsCanvasSlot(SlotUniform)->SetSize(GridSize);
	UWidgetLayoutLibrary::SlotAsCanvasSlot(Uniform_Bg)->SetSize(GridSize);
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		SlotUniform->AddChildToUniformGrid(CreateWidget<UUserWidget>(GetWorld(), SlotClass), i % sizeX, i / sizeY);
	}

}
