// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

APawnTurret::APawnTurret()
{
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	// Bind CheckFireCondition to timer and also provide the timer value i.e, FireRate
	// "this" is the current class i.e., APawnTurret
	// the last argument is true to enable looping i.e., the timer continues to run and doesn't stop after FireRate seconds
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
	// If Player is null || is DEAD, then "BAIL"!
	// If Player is in RANGE, then FIRE!!
	UE_LOG(LogTemp, Warning, TEXT("Checking fire condition at %f"), GetWorld()->GetTimeSeconds());
}