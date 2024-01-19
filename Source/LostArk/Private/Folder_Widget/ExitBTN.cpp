#include "Folder_Widget/ExitBTN.h"

//void UExitBTN::PostLoad()
//{
//	Super::PostLoad();
//	OnClicked.RemoveAll(this);
//	OnClicked.AddDynamic(this, &UExitBTN::ExitWidget);
//}

void UExitBTN::ExitWidget()
{
	UE_LOG(LogTemp, Log, TEXT("// ExitWidget"));
}
