#include "GI_LostArk.h"
#include "Folder_Character/PC_Base.h"
#include "Kismet/GameplayStatics.h"

UGI_LostArk::UGI_LostArk()
	: currScene(EScene::NONE)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> JobMeshTableSearch(TEXT("/Game/DataTable/MeshTable"));
	if (JobMeshTableSearch.Succeeded())
	{
		JobMeshTable = JobMeshTableSearch.Object;
	}
}

void UGI_LostArk::ChangeLevel(float _CameraTime, const FName& _LevelName)
{
	
	APC_Base* PC = Cast<APC_Base>(GetWorld()->GetFirstPlayerController());
	if (!PC)
		return;

	PC->FadeIn(_CameraTime);
	FTimerDelegate TimerDelegate;
	FTimerHandle TimerHandle;
	FName LevelName = _LevelName;


	TimerDelegate.BindLambda([this, LevelName]()
		{
			UGameplayStatics::OpenLevel(GetWorld()->GetFirstPlayerController(), LevelName);
		});

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, _CameraTime, false);
}

void UGI_LostArk::StartLevel(float _CameraTime)
{
	APC_Base* PC = Cast<APC_Base>(GetWorld()->GetFirstPlayerController());
	if (!PC)
		return;

	PC->FadeOut(_CameraTime);
}

