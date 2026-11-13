#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

class AWeaponBase;
class USceneComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTINGSYSTEM_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()


private:

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Combat", Transient, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWeaponBase> EquippedWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<AWeaponBase> StartingWeaponClass;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Combat", Transient, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> WeaponAttachPoint;




public:	

	UCombatComponent();

	UFUNCTION()
	void InitializeStartingWeapon(USceneComponent* AttachParent);

	UFUNCTION()
	void EquipWeapon(AWeaponBase* NewWeapon);

	UFUNCTION()
	void FireWeapon(const FVector& CameraStart, const FVector& CameraDirection);


};
