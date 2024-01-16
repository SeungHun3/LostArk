#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StatusWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UStatusWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// HP
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UProgressBar* HP_Bar;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UProgressBar* MP_Bar;


	// Skill Slot
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class USkillWidget* Q_Skill;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class USkillWidget* W_Skill;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class USkillWidget* E_Skill;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class USkillWidget* R_Skill;
	
	//// Item Slot
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* F1_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num1_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num2_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num3_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num4_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num5_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num6_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num7_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num8_Item;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	//class UUserWidget* Num9_Item;



};
