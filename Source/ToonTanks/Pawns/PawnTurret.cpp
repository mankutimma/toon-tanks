// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

// The static-tank that fires at the player-tank

#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "PawnTank.h"


APawnTurret::APawnTurret()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor is doing nothing!"));
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	// Bind CheckFireCondition to timer and also provide the timer value i.e, FireRate
	// "this" is the current class i.e., APawnTurret
	// the last argument is true to enable looping i.e., the timer continues to run and doesn't stop after FireRate seconds
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	// cast is a way for cross-class communication. Here, APawn is cast to APawnTank
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0)); // PLayer 0 is the only player in a single-player game

	// TEST();
}

//void APawnTurret::TEST()
//{
//	// Super calls code within the base class method
//	Super::TEST();
//	UE_LOG(LogTemp, Warning, TEXT("Inside PawnTurret class"));
//}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
	// If Player is null || is DEAD, then "BAIL"!
	if (!PlayerPawn)
	{
		return;
	}

	// If Player is in RANGE, then FIRE!!
	if (ReturnDistanceToPlayerPawn() <= FireRange)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire condition successful at %f"), GetWorld()->GetTimeSeconds());
	}
}

float APawnTurret::ReturnDistanceToPlayerPawn() const
{
	if (!PlayerPawn)
	{
		return -1.f;
	}

	// GetOwner()->GetActorLocation() instead of just GetActorLocation() crashes unreal with a fatal error upon clicking play button.
	// Why does this happen?
	float Distance = FVector::Dist(GetActorLocation(), PlayerPawn->GetActorLocation());
	return Distance;
}
