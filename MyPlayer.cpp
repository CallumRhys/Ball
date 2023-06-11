// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create components
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraMesh"));
	RootComponent = CameraMesh;

	//Setup Camera
	Camera->FieldOfView = 120.f;
	Camera->SetRelativeLocationAndRotation(FVector(-200.0f, 0.0f, 200.0f), FRotator(-45.0f, 0.0f, 0.0f));
	Camera->SetupAttachment(CameraMesh);

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Gravity
	FVector gravity = GetActorLocation();
	gravity.Z += -1;
	SetActorLocation(gravity);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Register LR Movement
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, & AMyPlayer::MoveLR);

	//Register FB Movement
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AMyPlayer::MoveFB);
}

void AMyPlayer::MoveLR(float MovementDelta)
{
	FVector newLocation = GetActorLocation();
	newLocation.X += MovementDelta * MovementSpeed;
	SetActorLocation(newLocation);
}

void AMyPlayer::MoveFB(float FBMovementDelta)
{
	FVector newLocationFB = GetActorLocation();
	newLocationFB.Y += FBMovementDelta * MovementSpeed;
	SetActorLocation(newLocationFB);
}

