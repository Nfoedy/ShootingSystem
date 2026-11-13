#include "Weapons/WeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"

// Debug
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


}


void AWeaponBase::Fire()
{
    if (!GetWorld()) return;
 
    const FVector Start = MuzzlePoint->GetComponentLocation();
    const FVector Direction = MuzzlePoint->GetForwardVector();
    const FVector End = Start + (Direction * TraceRange);

    FHitResult Hit;

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);
    
    DrawDebugLine(
        GetWorld(),
        Start,
        bHit ? Hit.ImpactPoint : End,
        bHit ? FColor::Green : FColor::Red,
        false,
        5.0f,
        0,
        2.0f
    );


    if (GEngine)
    {
        if (bHit)
        {
            GEngine->AddOnScreenDebugMessage(
                -1,
                3.0f,
                FColor::Green,
                FString::Printf(TEXT("Hit: %s"), *GetNameSafe(Hit.GetActor()))
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