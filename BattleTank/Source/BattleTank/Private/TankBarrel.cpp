// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {

  RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawElevation = RelativeRotation.Pitch + ElevationChange;
	auto NewElevation = FMath::Clamp<float>(RawElevation, MinDegreesElevation, MaxDegreesElevation);

	SetRelativeRotation( FRotator(NewElevation, 0, 0) );
}
