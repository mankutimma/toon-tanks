// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

// The static-tank that fires at the player-tank

#pragma once

#include "CoreMinimal.h"
#include "Pawns/PawnBase.h"
#include "Pawns/PawnTank.h"
#include "PawnTurret.generated.h"

//class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	// FireRate says "fire every x seconds" when "CheckFireCondition" is met
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.f;

	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn = nullptr;

	void CheckFireCondition();
	float ReturnDistanceToPlayerPawn() const;

public:
	// constructor
	APawnTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void HandleDestruction() override;

	// override is added to avoid ambiguity and not really for functionality. It is for the system/compiler and developers to know that
	// this method isn't a new one but an extension of the method from the base/parent class

	// "override" keyword in the declaration of the extension function (in inherited class)
	// and the "virtual" keyword in the declaration of the function in the base class go hand in hand

	// Without the "override" - "virtual" pair, functions can be overridden but don't offer transparency to developers

	// The "virtual" keyword helps the developer understand that the method is overridden in the inherited classes and modification of the
	// base class method should be done with caution
	/*void TEST() override;*/
};
