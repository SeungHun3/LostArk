#pragma once

#include "CoreMinimal.h"
#include "Folder_Character/Player/Weapon.h"

#include "Folder_Character/CharacterBase.h"
#include "NPCBase.generated.h"


UENUM(BlueprintType)
enum class ENPCType : uint8
{
	Shop,
	Quest,
};


UCLASS()
class LOSTARK_API ANPCBase : public ACharacterBase
{
	GENERATED_BODY()

public:
	ANPCBase();
	ENPCType type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UShopWidget> ShopWidget;
	bool IsOpenWidget;

	UDataTable* Items;

	void Clicked();


};
