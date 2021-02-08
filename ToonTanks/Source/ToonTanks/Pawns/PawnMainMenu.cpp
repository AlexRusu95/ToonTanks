// Alex Rusu 2021 - Toon Tanks


#include "ToonTanks/Pawns/PawnMainMenu.h"

// Sets default values
APawnMainMenu::APawnMainMenu()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnMainMenu::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnMainMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnMainMenu::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

