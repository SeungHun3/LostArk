#include "Folder_Widget/Folder_InGame/SkillWidget.h"
#include "Components/Image.h"
#include "TimerManager.h"

void USkillWidget::NativeConstruct()
{
	Super::NativeConstruct();

    TimerDelegate.BindLambda([this]()
        {
            if (time > CoolTime) {
                time = 0.f;
                SetSkillPercent(1.f);
                GetOwningPlayerPawn()->GetWorldTimerManager().ClearTimer(TimerHandle);
                return;
            }
            SetSkillPercent(time);
            time += 0.1f;

        });

}

void USkillWidget::SetImage(const FString& _MaterialPath, float _CoolTime)
{
    UMaterialInterface* LoadedMaterial = LoadObject<UMaterialInterface>(nullptr, *_MaterialPath);
    if (LoadedMaterial)
    {
        TargetMaterial = UMaterialInstanceDynamic::Create(LoadedMaterial, this);
        if (TargetMaterial)
        {
            Skill_Image->SetBrushFromMaterial(TargetMaterial);
            CoolTime = _CoolTime;
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
    UE_LOG(LogTemp, Log, TEXT("// StartAnim : cool Time : %f"), CoolTime);
    
    GetOwningPlayerPawn()->GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, 0.1f, true, 0.f);
}
