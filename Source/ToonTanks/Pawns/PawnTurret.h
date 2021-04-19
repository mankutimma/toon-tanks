// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/PawnBase.h"
#include "PawnTurret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	// FireRate says "fire every x seconds" when "CheckFireCondition" is met
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;

	void CheckFireCondition();

	FTimerHandle FireRateTimerHandle;

public:
	// constructor
	APawnTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};