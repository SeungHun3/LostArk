#include "Folder_Character/Player/PlayerBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Folder_Component/InputSystem.h"
#include "Folder_Component/WidgetSystem.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Character/State.h"
#include "Folder_Interface/Click.h"
#include "GI_LostArk.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"	
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Folder_Anim/AnimBase_Character.h"

APlayerBase::APlayerBase()
	:OwingController(nullptr), ClickedTarget(nullptr), Job(EJob::None)
{
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 1000.0f;
	CameraBoom->SetRelativeRotation(FRotator(-50.f, 0.f, 0.f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bInheritYaw = false;
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	InputSystem = CreateDefaultSubobject<UInputSystem>(TEXT("InputSystem"));
	WidgetSystem = CreateDefaultSubobject<UWidgetSystem>(TEXT("WidgetSystem"));
	CursorFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/Asset/MouseCursor/FX_Cursor"));

	GetMesh()->SetVisibility(false);
}

void APlayerBase::ConvertProperty(int _str, int _dex, int _intelligent)
{
	if (Job == EJob::None)
	{
		TotalInfo.SetPower(_str * 5);

	}
}


void APlayerBase::Init_Complete(int _str, int _dex, int _intelligent)
{
	UE_LOG(LogTemp, Log, TEXT("//Complete"));
	ConvertProperty(_str, _dex, _intelligent);


}




void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	OwingController = Cast<APC_Base>(NewController);
	AState* state = NewController->GetPlayerState<AState>();
	if (state && OwingController)
	{
		state->Init(1); // 인게임진입시 데이터 가져오기 => 리팩토링 예정
	}
}



void APlayerBase::LeftClicked()
{
	//Skill_Base();
}

void APlayerBase::RightClicked()
{
	if (ClickedTarget && (GetActorLocation() - Cast<AActor>(ClickedTarget)->GetActorLocation()).GetAbs().Size() < 500.f) // 거리체크
	{
		ClickedTarget->RightClicked();
		DisableInput(OwingController);
		SetMovement(false);
	}
	else
	{
		Move();
	}
}

void APlayerBase::Move() // 몬스터 타겟이 있다면 따라간 후 기본공격
{
	if (OwingController)
	{
		FHitResult HitResult;
		OwingController->GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, true, HitResult);
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(OwingController, HitResult.Location);
		UE_LOG(LogTemp,Log, TEXT("// Move : %f, %f"), HitResult.Location.X, HitResult.Location.Y);
		if (CursorFX)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, CursorFX, HitResult.Location, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
		}
		//else // 없다면 디폴트 fx로 교체
		{

		}
	}
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		FCharaterInfo* PlayerInfo = pGI->GetPlayerInfo();
		if ((pGI->GetCurrScene() == EScene::InGame) && (PlayerInfo))
		{
			GetMesh()->SetSkeletalMesh(PlayerInfo->Mesh);
			Job = PlayerInfo->Job;
			GetMesh()->SetVisibility(true);
			SetCameraMode(true);
		}
		else
		{
			GetMesh()->SetVisibility(false);
			SetCameraMode(false);
		}
	}
}

void APlayerBase::LevelUp()
{
	UE_LOG(LogTemp, Log, TEXT("// LevelUp"));
}

void APlayerBase::Skill(ESkill eSkill)
{
	switch (eSkill)
	{
	case ESkill::Base:
		Skill_Base();
		break;
	}
}

void APlayerBase::Skill_Base()
{
	UAnimBase_Character* anim = Cast<UAnimBase_Character>(GetMesh()->GetAnimInstance());
	if (anim && anim->GetAnimState() == ESkill::NONE)
	{
		SetMovement(false);
		anim->ChangeState(ESkill::Base);
		Delegate_Skill_Base.Broadcast();
	}
}

void APlayerBase::UseItem()
{
}

void APlayerBase::ChangeWeapon()
{
}

void APlayerBase::SetCameraMode(bool _IsTop)
{
	if (_IsTop)
	{
		CameraBoom->TargetArmLength = 1000.0f;
		CameraBoom->SetRelativeRotation(FRotator(-50.f, 0.f, 0.f));
	}
	else
	{
		CameraBoom->TargetArmLength = 300.0f;
		CameraBoom->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
	}
}
