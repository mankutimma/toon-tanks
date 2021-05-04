// Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	// Since we declared CapsuleComp first, Unreal will flag it as RootComponent and put it at the top of the hierarchy. Nevertheless, for developer reference, assigning it to RootComponent.
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent); // We want BaseMesh to inherit the movement of the capsule component below it.

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

void APawnBase::RotatePawnHead(FVector TargetLocation)
{
	// Update TurretMesh rotation to face towards TargetLocation passed in from child classes
	// TurretMesh->SetWorldRotation()...

	// "z" of the vector is TurretMesh's or pawn-head's location since we do not want the rotation to happen in z-axis i.e., vertical
	FVector LookAtTarget = FVector(TargetLocation.X, TargetLocation.Y, TurretMesh->GetComponentLocation().Z);

	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator PawnHeadRotation = FVector(LookAtTarget - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(PawnHeadRotation);
}

void APawnBase::Fire()
{
	// Get ProjectileSpawnPoint "location" and "rotation" -> Spawn Projectile class at "location" firing towards "rotation"
	UE_LOG(LogTemp, Warning, TEXT("Fire condition successful at %f"), GetWorld()->GetTimeSeconds());
}

void APawnBase::HandleDestruction()
{
	// --- Universal functionality ---
	// Play death effects, particle, sound and camera shake

	// --- Then do child overrides ---
	// PawnTurret - Inform GameMode Turret/shooter died -> Then Destroy() self

	// --- Then do child overrides ---
	// PawnTank -> Inform GameMode Player died -> Then hide all visual components 
	// (and not just the player camera component because then hard switch happens to the default camera its not good UX) and disable movement
}


// virtual is added to 
//void APawnBase::TEST()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Inside PawnBase class"));
//}
