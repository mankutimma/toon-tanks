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

	// For axis bindings and to calculate the direction of movement
	// Value is 0 when nothing is pressed and 1 when 'W' is pressed and -1 when 'S' is pressed. This is defined in Edit -> Project Settings -> Engine -> Input -> Axis mappings 
	void CalculateMoveInput(float Value);
	
	// For axis bindings and to calculate the direction of rotation
	void CalculateRotateInput(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
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
