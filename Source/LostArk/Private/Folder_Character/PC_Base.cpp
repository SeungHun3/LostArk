#include "Folder_Character/PC_Base.h"
#include "Kismet/GameplayStatics.h"

APC_Base::APC_Base(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer), OwnedPlayer(nullptr)
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
    bEnableTouchEvents = true;
    bEnableTouchOverEvents = true;
}

void APC_Base::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

}



void APC_Base::SetupInputComponent()
{
    Super::SetupInputComponent();
    bEnableClickEvents = false;
    bEnableTouchEvents = false;
    bEnableMouseOverEvents = false;
    bEnableTouchOverEvents = false;
}

void APC_Base::FadeOut(float time)
{
    float fadetime = time - 2.f;
    UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->StartCameraFade(1.f, 0.f, fadetime, FColor::Black, true, true);

    bEnableClickEvents = true;
    bEnableTouchEvents = true;
    bEnableMouseOverEvents = true;
    bEnableTouchOverEvents = true;
}

void APC_Base::FadeIn(float time)
{
    float fadetime = time - 2.f;
    UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->StartCameraFade(0.f, 1.f, fadetime, FColor::Black,true, true);
    bEnableClickEvents = false;
    bEnableTouchEvents = false;
    bEnableMouseOverEvents = false;
    bEnableTouchOverEvents = false;
}

