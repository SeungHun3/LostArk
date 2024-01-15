#include "GM_Create.h"
#include "GI_LostArk.h"
#include "Folder_Character/PC_Base.h"

AGM_Create::AGM_Create()
{
	UE_LOG(LogTemp, Log, TEXT("//AGM_Create"));
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/BP_PlayerBase"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = APC_Base::StaticClass();
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
