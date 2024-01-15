#include "Folder_Widget/LobbyHUD.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Folder_Character/PC_Base.h"

void ULobbyHUD::NativeConstruct()
{
	Super::NativeConstruct();
	
	InGameBTN->OnClicked.AddDynamic(this, &ULobbyHUD::InGame);
	APC_Base* PC = Cast<APC_Base>(GetWorld()->GetFirstPlayerController());
	if (!PC)
		return;

	float time = 5.f;
	PC->FadeOut(time);

}

void ULobbyHUD::InGame()
{
	APC_Base* PC = Cast<APC_Base>(GetWorld()->GetFirstPlayerController());
	if (!PC)
		return;

	SetVisibility(ESlateVisibility::Collapsed);
	float time = 5.f;
	PC->FadeIn(time);
	FTimerDelegate TimerDelegate;

	TimerDelegate.BindLambda([this]()
		{
			UGameplayStatics::OpenLevel(GetWorld()->GetFirstPlayerController(), "InGame");
		});

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, time, false);

}
