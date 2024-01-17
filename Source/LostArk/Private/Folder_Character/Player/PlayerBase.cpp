#include "Folder_Character/Player/PlayerBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Folder_Component/InputSystem.h"
#include "Folder_Component/WidgetSystem.h"
#include "Folder_Character/PC_Base.h"
#include "Folder_Character/State.h"

APlayerBase::APlayerBase()
{
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	InputSystem = CreateDefaultSubobject<UInputSystem>(TEXT("InputSystem"));
	WidgetSystem = CreateDefaultSubobject<UWidgetSystem>(TEXT("WidgetSystem"));

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

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayerBase::LookUpAtRate);

}

void APlayerBase::PossessedBy(AController* NewController)
{
	AState* state = NewController->GetPlayerState<AState>();
	if (state)
	{
		UE_LOG(LogTemp, Log, TEXT("//state"));
		state->Init(1);
	}

}

void APlayerBase::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerBase::MoveRight(float Value)
{

	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerBase::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerBase::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerBase::LevelUp()
{
	UE_LOG(LogTemp, Log, TEXT("// LevelUp"));
}

void APlayerBase::Skill_Q()
{
	UE_LOG(LogTemp, Log, TEXT("// Skill_Q"));
	Delegate_Skill_Q.Broadcast();
}

void APlayerBase::Skill_W()
{
	UE_LOG(LogTemp, Log, TEXT("// Skill_W"));
}
