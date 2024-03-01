#include "Folder_Character/NPC/NPCBase.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "Folder_Component/InputSystem.h"
#include "Folder_Widget/Folder_InGame/ShopWidget.h"
#include "Components/CapsuleComponent.h"
ANPCBase::ANPCBase()
{
	GetCapsuleComponent()->SetCollisionProfileName(FName("NPC"));
	OnBeginCursorOver.AddDynamic(this, &ANPCBase::BeginCursorOver);
	OnEndCursorOver.AddDynamic(this, &ANPCBase::EndCursorOver);
	type = ENPCType::Shop;
}


void ANPCBase::BeginCursorOver(AActor* TouchedActor)
{
	// 테두리 On
	APlayerBase* player = Cast<APlayerBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player)
	{
		player->ClickedTarget = this;

	}
}

void ANPCBase::EndCursorOver(AActor* TouchedActor)
{
	// 테두리 Off	
	APlayerBase* player = Cast<APlayerBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player)
	{
		player->ClickedTarget = nullptr;
	}
}

void ANPCBase::RightClicked()
{
	EndCursorOver(this);
	UUserWidget* pShopWidget = CreateWidget<UUserWidget>(GetWorld(), ShopWidget);
	if (pShopWidget)
	{
		pShopWidget->AddToViewport();
	}
	UE_LOG(LogTemp, Log, TEXT("//Create ShopWidget"));

}
