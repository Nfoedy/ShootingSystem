#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class USkeletalMeshComponent;
class UArrowComponent;
class UBoxComponent;

UCLASS()
class SHOOTINGSYSTEM_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
private:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> SceneRoot;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true", ClampMin = "1.0"))
	float TraceRange;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UArrowComponent> MuzzlePoint;


	UPROPERTY()
	TObjectPtr<UBoxComponent> PickupCollision;

public:	

	AWeaponBase();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire(const FVector& CameraStart, const FVector& CameraDirection);

	UFUNCTION()
	void SetPickupEnabled(bool bEnabled);

};
