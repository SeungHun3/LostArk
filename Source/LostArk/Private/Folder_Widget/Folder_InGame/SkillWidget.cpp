#include "Folder_Widget/Folder_InGame/SkillWidget.h"
#include "Components/Image.h"
#include "TimerManager.h"

void USkillWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void USkillWidget::SetImage(const FString& _MaterialPath)
{
    UMaterialInterface* LoadedMaterial = LoadObject<UMaterialInterface>(nullptr, *_MaterialPath);
    if (LoadedMaterial)
    {
        TargetMaterial = UMaterialInstanceDynamic::Create(LoadedMaterial, this);
        if (TargetMaterial)
        {
            Skill_Image->SetBrushFromMaterial(TargetMaterial);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load material at path: %s"), *_MaterialPath);
    }

}

void USkillWidget::SetSkillPercent(float _Percent)
{
    if (TargetMaterial)
    {
        TargetMaterial->SetScalarParameterValue(FName("Percent"), _Percent);
    }
}

void USkillWidget::StartAnim()
{
    UE_LOG(LogTemp, Log, TEXT("// StartAnim"));
    TimerDelegate.BindLambda([this]()
        {
            if (time > 1.f)
            {
                time = 0.f;
                GetOwningPlayerPawn()->GetWorldTimerManager().ClearTimer(TimerHandle);
            }
            SetSkillPercent(time);
            time += 0.1f;

        });
    GetOwningPlayerPawn()->GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, 1.f, true);
}
