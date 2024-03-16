#include "Folder_Widget/LobbyHUD.h"
#include "Components/Button.h"
#include "GI_LostArk.h"

void ULobbyHUD::NativeConstruct()
{
	Super::NativeConstruct();

	UGI_LostArk *GI = Cast<UGI_LostArk>(GetGameInstance());
	if (GI)
	{
		GI->StartLevel(3.f);
	}

	GetOwningPlayerPawn()->DisableInput(GetWorld()->GetFirstPlayerController());

	InGameBTN->OnClicked.AddDynamic(this, &ULobbyHUD::InGame);
	CreateBTN->OnClicked.AddDynamic(this, &ULobbyHUD::Create);
}

void ULobbyHUD::InGame() // 서버데이터 받거나 SaveGame 저장 = 현재는 Default 로 Warrior 넣음
{
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		USkeletalMesh* Mesh = ResourceMgr::GetInst()->GetPlayerMesh(EJob::Warrior);
		if (Mesh)
		{
			pGI->SetPlayerInfo(EJob::Warrior);
			pGI->ChangeLevel(3.f, "InGame");
			SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

void ULobbyHUD::Create()
{
	UGI_LostArk* GI = Cast<UGI_LostArk>(GetGameInstance());
	if (GI)
	{
		GI->ChangeLevel(3.f, "Create");
		SetVisibility(ESlateVisibility::Collapsed);
	}
}
