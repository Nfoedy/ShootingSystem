#include "Components/CombatComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "Weapons/WeaponBase.h"


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	EquippedWeapon = nullptr;

}


void UCombatComponent::InitializeStartingWeapon(USceneComponent* AttachParent)
{
	if (!IsValid(AttachParent)) return;

	WeaponAttachPoint = AttachParent;

	if (!StartingWeaponClass) return;

	if (IsValid(EquippedWeapon)) return;

	UWorld* World = GetWorld();
	AActor* Owner = GetOwner();

	if (!IsValid(World) || !IsValid(Owner)) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Owner;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AWeaponBase* NewWeapon = World->SpawnActor<AWeaponBase>(StartingWeaponClass, WeaponAttachPoint->GetComponentTransform(), SpawnParams);

	if (!IsValid(NewWeapon)) return;

	EquipWeapon(NewWeapon);
}




void UCombatComponent::EquipWeapon(AWeaponBase* NewWeapon)
{
    if (!IsValid(NewWeapon)) return;
    if (!IsValid(WeaponAttachPoint)) return;
	if (IsValid(EquippedWeapon)) return;
	
	AActor* OwnerActor = GetOwner();
    if (!IsValid(OwnerActor)) return;

	NewWeapon->SetPickupEnabled(false);

    const bool bAttached = NewWeapon->AttachToComponent(WeaponAttachPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	if (!bAttached) {
		NewWeapon->SetPickupEnabled(true);
		return;
	}
	
	NewWeapon->SetOwner(OwnerActor);
	
	EquippedWeapon = NewWeapon;
}




void UCombatComponent::FireWeapon(const FVector& CameraStart, const FVector& CameraDirection)
{
	if (!IsValid(EquippedWeapon)) return;

	EquippedWeapon->Fire(CameraStart, CameraDirection);
}


