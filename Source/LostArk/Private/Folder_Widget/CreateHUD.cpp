#include "Folder_Widget/CreateHUD.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "GI_LostArk.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Character/CharacterBase.h"
#include "Folder_Component/InputSystem.h"
#include "Kismet/GameplayStatics.h"

void UCreateHUD::NativeConstruct()
{
	Super::NativeConstruct();
	APC_Base* PC = Cast<APC_Base>(GetWorld()->GetFirstPlayerController());

	if (!PC)
		return;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Target"), FoundActors);
	if (FoundActors.IsValidIndex(0))
	{
		TargetCharacter = Cast<ACharacterBase>(FoundActors[0]);
		if (TargetCharacter)
		{
			TargetCharacter->Job = EJob::Warrior;
			JobName->SetText(FText::FromString("Warrior"));
		}
	}

	GetOwningPlayerPawn()->DisableInput(GetWorld()->GetFirstPlayerController());

	float time = 5.f;
	PC->FadeOut(time);

	SelectJobBTN->OnClicked.AddDynamic(this, &UCreateHUD::ClickedJob);
	CreateBTN->OnClicked.AddDynamic(this, &UCreateHUD::Create);
}

void UCreateHUD::ClickedJob()
{
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());

	if (pGI && TargetCharacter)
	{
		FCharaterMesh* TargetMesh = nullptr;
		TargetCharacter->Job == EJob::Warrior ? TargetCharacter->Job = EJob::Hunter : TargetCharacter->Job = EJob::Warrior;


		switch (TargetCharacter->Job)
		{
		case EJob::Warrior:

			TargetMesh = pGI->JobMesh->FindRow<FCharaterMesh>(FName("Warrior"), "");
			if (TargetMesh->Mesh)
			{
				TargetCharacter->GetMesh()->SetSkeletalMesh(TargetMesh->Mesh);
				JobName->SetText(FText::FromString("Warrior"));
			}
			
			break;

		case EJob::Hunter:
			TargetMesh = pGI->JobMesh->FindRow<FCharaterMesh>(FName("Hunter"), "");
			if (TargetMesh->Mesh)
			{
				TargetCharacter->GetMesh()->SetSkeletalMesh(TargetMesh->Mesh);
				JobName->SetText(FText::FromString("Hunter"));
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
	APC_Base* PC = Cast<APC_Base>(GetWorld()->GetFirstPlayerController());
	if (!PC)
		return;

	SetVisibility(ESlateVisibility::Collapsed);
	float time = 5.f;
	PC->FadeIn(time);
	FTimerDelegate TimerDelegate;

	TimerDelegate.BindLambda([this]()
		{
			UGameplayStatics::OpenLevel(GetWorld()->GetFirstPlayerController(), "InGame");
		});

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, time, false);
}
