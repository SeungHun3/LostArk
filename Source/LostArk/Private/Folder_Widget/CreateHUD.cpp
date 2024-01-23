#include "Folder_Widget/CreateHUD.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "GI_LostArk.h"

#include "Folder_Character/PC_Base.h"
#include "Folder_Character/CharacterBase.h"
#include "Folder_Component/InputSystem.h"

#include "GI_LostArk.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

void UCreateHUD::NativeConstruct()
{
	Super::NativeConstruct();

	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		pGI->StartLevel(3.f);
	}


	for (TActorIterator<ACharacterBase> ActorItr(GetWorld(), ACharacterBase::StaticClass()); ActorItr; ++ActorItr)
	{
		TargetCharacter = *ActorItr;
		if (TargetCharacter && TargetCharacter->ActorHasTag("Target"))
		{
			TargetCharacter->Job = EJob::Warrior;
			JobName->SetText(FText::FromString("Warrior"));
			FCharaterInfo* TargetInfo = pGI->JobMeshTable->FindRow<FCharaterInfo>(FName("Warrior"), "");
			if (TargetInfo)
			{
				pGI->SetPlayerInfo(TargetInfo);
			}

			break;
		}
	}

	GetOwningPlayerPawn()->DisableInput(GetWorld()->GetFirstPlayerController());


	SelectJobBTN->OnClicked.AddDynamic(this, &UCreateHUD::ClickedJob);
	CreateBTN->OnClicked.AddDynamic(this, &UCreateHUD::Create);
}

void UCreateHUD::ClickedJob()
{
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());

	if (pGI && TargetCharacter)
	{
		FCharaterInfo* TargetInfo = nullptr;
		TargetCharacter->Job == EJob::Warrior ? TargetCharacter->Job = EJob::Hunter : TargetCharacter->Job = EJob::Warrior;


		switch (TargetCharacter->Job)
		{
		case EJob::Warrior:
		
			TargetInfo = pGI->JobMeshTable->FindRow<FCharaterInfo>(FName("Warrior"), "");
			if (TargetInfo && TargetInfo->Mesh)
			{
				TargetCharacter->GetMesh()->SetSkeletalMesh(TargetInfo->Mesh);
				JobName->SetText(FText::FromString("Warrior"));
				pGI->SetPlayerInfo(TargetInfo);
			}
			
			break;
		
		case EJob::Hunter:
			TargetInfo = pGI->JobMeshTable->FindRow<FCharaterInfo>(FName("Hunter"), "");
			if (TargetInfo && TargetInfo->Mesh)
			{
				TargetCharacter->GetMesh()->SetSkeletalMesh(TargetInfo->Mesh);
				JobName->SetText(FText::FromString("Hunter"));
				pGI->SetPlayerInfo(TargetInfo);
			}
		
			break;

		}
	}
}

void UCreateHUD::Create()
{
	InGame();
}

void UCreateHUD::InGame()
{
	UGI_LostArk* GI = Cast<UGI_LostArk>(GetGameInstance());
	if (GI)
	{
		GI->ChangeLevel(3.f, "InGame");
	}
	SetVisibility(ESlateVisibility::Collapsed);
}
