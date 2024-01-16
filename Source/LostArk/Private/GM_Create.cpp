#include "GM_Create.h"
#include "GI_LostArk.h"
#include "ResourceMgr.h"
#include "Folder_Character/PC_Base.h"

AGM_Create::AGM_Create()
{
	FString PlayerRes = ResourceMgr::GetInst()->GetCreatePlayerRes();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass((TEXT("%s"), *PlayerRes));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = APC_Base::StaticClass();

	ResourceMgr::GetInst()->GetCreateTargetRes();
}

void AGM_Create::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		pGI->SetCurrScene(EScene::Create);
	}
}

void AGM_Create::BeginPlay()
{
}
