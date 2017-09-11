// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	//auto ControlledTank = GetControlledTank();
	PlayerTank = GetPlayerTank();
	ControlledTank = GetControlledTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController has no player tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AIController has found player tank: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}
}


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
