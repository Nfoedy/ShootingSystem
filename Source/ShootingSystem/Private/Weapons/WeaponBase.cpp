#include "Weapons/WeaponBase.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
// Debug
#include "DrawDebugHelpers.h"
#include "Engine/World.h"



AWeaponBase::AWeaponBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // Weapon Mesh
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    SetRootComponent(WeaponMesh);

    WeaponMesh->SetCollisionObjectType(ECC_PhysicsBody);
    WeaponMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    WeaponMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
    WeaponMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    WeaponMesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
    WeaponMesh->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);

    WeaponMesh->SetEnableGravity(true);

    // Muzzle Point
    MuzzlePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("MuzzlePoint"));
    MuzzlePoint->SetupAttachment(WeaponMesh);
    MuzzlePoint->SetArrowSize(0.3f);

    // Pickup Collision
    PickupCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupCollision"));
    PickupCollision->SetupAttachment(WeaponMesh);

    PickupCollision->SetCollisionObjectType(ECC_WorldDynamic);
    PickupCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    PickupCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
    PickupCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    PickupCollision->SetSimulatePhysics(false);
}


void AWeaponBase::BeginPlay()
{
    Super::BeginPlay();

    SetPickupEnabled(true);
}



void AWeaponBase::Fire(const FVector& CameraStart, const FVector& CameraDirection)
{
    UWorld* World = GetWorld();

    if (!IsValid(World)) return;
    if (!IsValid(MuzzlePoint)) return;

    const FVector AimDirection = CameraDirection.GetSafeNormal();
    if (AimDirection.IsNearlyZero()) return;

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    if (AActor* WeaponOwner = GetOwner())
    {
        Params.AddIgnoredActor(WeaponOwner);
    }

    // Camera Trace
    const FVector CameraEnd = CameraStart + AimDirection * TraceRange;

    FHitResult CameraHit;

    const bool bCameraHit = World->LineTraceSingleByChannel(CameraHit, CameraStart, CameraEnd, ECC_Visibility, Params);

    const FVector TargetPoint = bCameraHit ? CameraHit.ImpactPoint : CameraEnd;

    // Weapon Trace
    const FVector MuzzleStart = MuzzlePoint->GetComponentLocation();
    const FVector ShotDirection = (TargetPoint - MuzzleStart).GetSafeNormal();

    if (ShotDirection.IsNearlyZero()) return;

    const FVector WeaponEnd = TargetPoint + ShotDirection * 10.0f;

    FHitResult WeaponHit;

    const bool bWeaponHit = World->LineTraceSingleByChannel(WeaponHit, MuzzleStart, WeaponEnd, ECC_Visibility, Params);

    // Visualizzazione delle traiettorie
    DrawDebugLine(World, CameraStart, TargetPoint, FColor::Blue, false, 3.0f, 0, 1.0f);

    DrawDebugLine(World, MuzzleStart, bWeaponHit ? WeaponHit.ImpactPoint : WeaponEnd, bWeaponHit ? FColor::Green : FColor::Red,
        false,
        3.0f,
        0,
        2.0f
    );
}



void AWeaponBase::SetPickupEnabled(bool bEnabled)
{
    if (!IsValid(WeaponMesh)) return;
    if (!IsValid(PickupCollision)) return;

    if (bEnabled)
    {
        // Arma a terra
        WeaponMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        WeaponMesh->SetEnableGravity(true);
        WeaponMesh->SetSimulatePhysics(true);

        PickupCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    }
    else
    {
        // Arma equipaggiata
        WeaponMesh->SetSimulatePhysics(false);
        WeaponMesh->SetEnableGravity(false);
        WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

        PickupCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }
}
