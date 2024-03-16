#include "Folder_Widget/Folder_InGame/StatusWidget.h"
#include "Folder_Widget/Folder_InGame/SkillWidget.h"
#include "Folder_Character/Player/PlayerBase.h"
#include "ResourceMgr.h"

void UStatusWidget::NativeConstruct()
{
	Super::NativeConstruct();
    APlayerBase* Player = Cast<APlayerBase>(GetOwningPlayerPawn());
    if (!Player)
        return;

    EJob PlayerJob = Player->Job;
    float CoolTime = 1.f;

    FString MaterialPath_Q = ResourceMgr::GetInst()->GetSkill_QPath(PlayerJob);
    Q_Skill->SetImage(MaterialPath_Q, CoolTime);
    //Player->Delegate_Skill_Q.AddDynamic(Q_Skill, &USkillWidget::StartAnim);

    FString MaterialPath_W = ResourceMgr::GetInst()->GetSkill_WPath(PlayerJob);
    W_Skill->SetImage(MaterialPath_W, CoolTime);
    //Player->Delegate_Skill_W.AddDynamic(W_Skill, &USkillWidget::StartAnim);

    FString MaterialPath_E = ResourceMgr::GetInst()->GetSkill_EPath(PlayerJob);
    E_Skill->SetImage(MaterialPath_E, CoolTime);

    FString MaterialPath_R = ResourceMgr::GetInst()->GetSkill_RPath(PlayerJob);
    R_Skill->SetImage(MaterialPath_R, CoolTime);

    
    
}
