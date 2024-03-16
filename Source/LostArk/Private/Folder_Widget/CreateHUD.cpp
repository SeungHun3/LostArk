#include "Folder_Widget/CreateHUD.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "GI_LostArk.h"
#include "ResourceMgr.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "Folder_Component/InputSystem.h"

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
			Job = EJob::Warrior;
			JobName->SetText(FText::FromString("Warrior"));
			
			USkeletalMesh* Mesh = ResourceMgr::GetInst()->GetPlayerMesh(Job);
			if (Mesh)
			{
				TargetCharacter->GetMesh()->SetSkeletalMesh(Mesh);
				pGI->SetPlayerInfo(Job);
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
		Job = Job == EJob::Warrior ? EJob::Hunter : EJob::Warrior;
		USkeletalMesh* Mesh = ResourceMgr::GetInst()->GetPlayerMesh(Job);
		if (!Mesh)
			return;

		switch (Job)
		{
		case EJob::Warrior:
			JobName->SetText(FText::FromString("Warrior"));
			break;

		case EJob::Hunter:
			JobName->SetText(FText::FromString("Hunter"));
			break;
		}

		TargetCharacter->GetMesh()->SetSkeletalMesh(Mesh);
		pGI->SetPlayerInfo(Job);
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
