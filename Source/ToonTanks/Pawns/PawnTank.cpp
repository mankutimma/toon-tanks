// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}
// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, APawnTank::CalculateMoveInput); // "this" is the "world context"
	PlayerInputComponent->BindAxis("Turn", this, APawnTank::CalculateRotateInput);
}

void APawnTank::CalculateMoveInput(float Value)
{
}

void APawnTank::CalculateRotateInput(float Value)
{
}

void APawnTank::Move()
{
}

void APawnTank::Rotate()
{
}