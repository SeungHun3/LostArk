#include "GM_InGame.h"
#include "GI_LostArk.h"
#include "ResourceMgr.h"
#include "Folder_Character/PC_Base.h"

AGM_InGame::AGM_InGame()
{
	FString PlayerRes = ResourceMgr::GetInst()->GetInGamePlayerRes(EJob::None);
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass((TEXT("%s"), *PlayerRes));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	UE_LOG(LogTemp, Log, TEXT("// InGame"));
	PlayerControllerClass = APC_Base::StaticClass();
}

void AGM_InGame::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		pGI->SetCurrScene(EScene::InGame);
	}
}

void AGM_InGame::BeginPlay()
{
	Super::BeginPlay();
}
