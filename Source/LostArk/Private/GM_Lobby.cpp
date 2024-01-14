#include "GM_Lobby.h"

AGM_Lobby::AGM_Lobby()
{
	UE_LOG(LogTemp, Log, TEXT("//AGM_Lobby"));

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
