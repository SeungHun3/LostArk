#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee,
	Range,
};


USTRUCT(Atomic, BlueprintType)
struct FWeaponInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USkeletalMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EWeaponType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Rate;
};

UCLASS()
class LOSTARK_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FWeaponInfo WeaponInfo;

	// anim, effect

};
