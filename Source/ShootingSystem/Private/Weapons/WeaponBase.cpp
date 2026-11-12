#include "Weapons/WeaponBase.h"
#include "Components/SkeletalMeshComponent.h"


AWeaponBase::AWeaponBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // Weapon Mesh
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    SetRootComponent(WeaponMesh);


}

