#include "Weapons/WeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Debug
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"


AWeaponBase::AWeaponBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // Scene Root
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    SetRootComponent(SceneRoot);


    // Weapon Mesh
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    WeaponMesh->SetupAttachment(SceneRoot);

    // Trace Range
    TraceRange = 2000.0f;

    // Muzzle Point
    MuzzlePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("MuzzlePoint"));
    MuzzlePoint->SetupAttachment(WeaponMesh);
    MuzzlePoint->SetArrowSize(0.3f);

    // Pickup Collision
    PickupCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupCollision"));
    PickupCollision->SetupAttachment(SceneRoot);


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

    const FVector CameraEnd = CameraStart + AimDirection * TraceRange;

    FHitResult CameraHit;
    const bool bCameraHit = World->LineTraceSingleByChannel(CameraHit, CameraStart, CameraEnd, ECC_Visibility, Params);

    const FVector TargetPoint = bCameraHit ? CameraHit.ImpactPoint : CameraEnd;

    const FVector MuzzleStart = MuzzlePoint->GetComponentLocation();

    const FVector ShotDirection = (TargetPoint - MuzzleStart).GetSafeNormal();

    const FVector WeaponEnd = TargetPoint + ShotDirection * 10.0f;

    FHitResult WeaponHit;
    const bool bWeaponHit = World->LineTraceSingleByChannel(WeaponHit, MuzzleStart, WeaponEnd, ECC_Visibility, Params);

    DrawDebugLine(World, CameraStart, TargetPoint, FColor::Blue, false, 3.0f, 0, 1.0f);

    DrawDebugLine(World, MuzzleStart, bWeaponHit ? WeaponHit.ImpactPoint : TargetPoint, bWeaponHit ? FColor::Green : FColor::Red, false, 3.0f, 0, 2.0f);

    if (GEngine)
    {
        if (bWeaponHit)
        {
            GEngine->AddOnScreenDebugMessage(
                -1,
                3.0f,
                FColor::Green,
                FString::Printf(
                    TEXT("Hit: %s"),
                    *GetNameSafe(WeaponHit.GetActor())
                )
            );
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(
                -1,
                3.0f,
                FColor::Red,
                TEXT("No Hit!")
            );
        }
    }
}



void AWeaponBase::SetPickupEnabled(bool bEnabled)
{
    if (!IsValid(PickupCollision)) return;

    PickupCollision->SetCollisionEnabled(bEnabled ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
}