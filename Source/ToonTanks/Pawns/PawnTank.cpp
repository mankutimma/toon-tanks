// // Copyright 2021 Ashish Jagadish, Inc. All Rights Reserved.

// The player-tank

#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#define OUT


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

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void APawnTank::HandleDestruction()
{
	Super::HandleDestruction();
	UE_LOG(LogTemp, Warning, TEXT("Destroying the opponent!"));
	// Hide visual components and disable movement
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate();
	Move();

	if (PlayerControllerRef)
	{
		FHitResult TraceHitResult;

		// Gets hits on the mouse pointer movement
		PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, OUT TraceHitResult);

		// Tracks the mouse pointer
		FVector HitLocation = TraceHitResult.ImpactPoint;

		RotatePawnHead(HitLocation);
	}
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput); // "this" is the "world context"
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);

	// "this" is the class context
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
}

void APawnTank::CalculateMoveInput(float Value)
{
	// Multiplying by frame rate "DeltaTimeSeconds" so that that similar distances are covered in fast and not so fast machines
	float MoveAmount = Value * MoveSpeed * GetWorld()->DeltaTimeSeconds;

	// No movement in y and z axes since the Tank is not holonomic
	MoveDirection = FVector(MoveAmount, 0, 0);
}

void APawnTank::CalculateRotateInput(float Value)
{
	float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;

	// Rotation only in yaw axis. Hence pitch and roll are zero
	FRotator Rotation = FRotator(0, RotateAmount, 0);
	RotationDirection = FQuat(Rotation);
}

void APawnTank::Move()
{
	// Adds a delta to the location of this component in its local reference frame. 
	// The second argument bSweep is true because we want collission to be active i.e., we do not want the tank to move through walls and floors
	AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
	// Adds a delta to the rotation of this component in its local reference frame. 
	AddActorLocalRotation(RotationDirection, true);
}