// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	// For visually representing the projectile
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh = nullptr;

	// TSubclassOf is a template class that provides UClass type safety. 
	// For instance, let's imagine that you are creating a projectile class that allows the designer to specify the damage type. 
	// You could just create a UPROPERTY of type UClass and hope the designer always assigns a class derived from UDamageType 
	// or you could use the TSubclassOf template to enforce the choice. The sample code below illustrates the difference:
	/** type of damage */
	// UPROPERTY(EditDefaultsOnly, Category = Damage)
		// UClass* DamageType;
	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType = nullptr; // class pointer
	// Also see class pointers vs object pointers answers by ScottSpadea here: https://answers.unrealengine.com/questions/462096/why-use-tsubclassof-and-not-just-the-class-itself.html#


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 1300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (AllowPrivateAccess = "true"))
	float Damage = 50.f;

	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
