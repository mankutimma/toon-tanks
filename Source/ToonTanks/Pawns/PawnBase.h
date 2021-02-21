// Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

// This is a forward declaration. A forward declaration is used instead of including a header file when variables/methods of the class do not have to be accessed.
// So, it is just used as a reference so that the compiler doesn't freak out when we use this class in our own APawnBase class.
// An advantage of forward declarations over header file includes is that it reduces compile time.
class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
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

public:
	// Sets default values for this pawn's properties
	APawnBase();
};
