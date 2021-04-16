// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera = nullptr;

	FVector MoveDirection;
	FQuat RotationDirection;

	// For axis bindings and to calculate the direction of movement and rotation
	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	float MoveSpeed = 100.f;
	float RotateSpeed = 100.f;

	// Functions to run on even tick. They will cause movement/rotation in the direction based on the calulations made in the CalculateMoveInput and CalculateRotateInput functions
	void Move();
	void Rotate();


public:
	// constructor
	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
