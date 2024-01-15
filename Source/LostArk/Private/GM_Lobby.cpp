#include "GM_Lobby.h"
#include "GI_LostArk.h"
#include "Folder_Character/PC_Base.h"

AGM_Lobby::AGM_Lobby()
{
	UE_LOG(LogTemp, Log, TEXT("//AGM_Lobby"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/BP_Charbase"));
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
		pGI->SetCurrScene(EScene::Scene01);
	}
}

void AGM_Lobby::BeginPlay()
{

}
