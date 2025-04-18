// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
*
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent {
	GENERATED_BODY()

public:
	// -1 is max downward movement +1 is max upwards
	void Elevate(float RelativeSpeed);


private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesElevation = 25;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesElevation = -2;

};
