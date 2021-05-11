// Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

// This is a forward declaration. A forward declaration is used instead of including a header file when variables/methods of the class do not have to be accessed.
// So, it is just used as a reference so that the compiler doesn't freak out when we use this class in our own APawnBase class.
// An advantage of forward declarations over header file includes is that it reduces compile time.
class UCapsuleComponent;

class AProjectileBase;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
	/* ******************************************* COMPONENTS SECTION ******************************************* */

	// Capsule component is used for simple collission
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UCapsuleComponent* CapsuleComp = nullptr;

	// We don't need to forward declare static mesh components or scene components since the APawn/Aactor class is already aware of what it is.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint = nullptr; //Scene component is a collection of data essentially with transforms so that we can place the projectile at a certain spawn point


	/* ******************************************* VARIABLES SECTION ******************************************* */

	// does it make sense to initialize class pointer to nullptr?
	// answer: yes, since the value comes from the designer who uses blueprint whether it is a BP_ProjectileBase or ProjectileBase or None (nullptr)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileBaseClass = nullptr;

public:
	// Sets default values for this pawn's properties
	APawnBase();

protected:
	void RotatePawnHead(FVector TargetLocation);

	void Fire();

	virtual void HandleDestruction();

	// The "virtual" keyword helps the developer understand that the method is overridden in the inherited classes and modification of the
	// base class method should be done with caution
	//virtual void TEST();
};
