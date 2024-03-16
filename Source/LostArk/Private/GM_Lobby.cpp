#include "GM_Lobby.h"
#include "GI_LostArk.h"
#include "ResourceMgr.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Character/Player/PlayerBase.h"
AGM_Lobby::AGM_Lobby()
{
	FString PlayerRes = ResourceMgr::GetInst()->GetLobbyPlayerBP_Path();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass((TEXT("%s"), *PlayerRes));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = APC_Base::StaticClass();
	
}

void AGM_Lobby::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		pGI->SetCurrScene(EScene::Lobby);
	}
}

void AGM_Lobby::BeginPlay()
{

}
