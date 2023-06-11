// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationComponent.h"

// Sets default values for this component's properties
URotationComponent::URotationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;

}


// Called when the game starts
void URotationComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void URotationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// on every frame change rotationg for a smooth rotating actor
	FRotator NewRotation = FRotator(PitchValue, YawValue, RollValue);

	FQuat QuatRotation = FQuat(NewRotation);

	AddLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

