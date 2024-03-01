#pragma once

#include "CoreMinimal.h"
#include "Folder_Character/Player/Weapon.h"
#include "Folder_Interface/Click.h"
#include "Folder_Character/CharacterBase.h"
#include "NPCBase.generated.h"


UENUM(BlueprintType)
enum class ENPCType : uint8
{
	None,
	Shop,
	Quest,
};


UCLASS()
class LOSTARK_API ANPCBase : public ACharacterBase, public IClick
{
	GENERATED_BODY()

public:
	ANPCBase();
	ENPCType type = ENPCType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UShopWidget> ShopWidget;
	

	UFUNCTION()
	void BeginCursorOver(AActor* TouchedActor);
	UFUNCTION()
	void EndCursorOver(AActor* TouchedActor);

	// click interface
	virtual void RightClicked() override;

};
