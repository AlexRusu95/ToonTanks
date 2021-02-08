// Alex Rusu 2021 - Toon Tanks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnMainMenu.generated.h"

UCLASS()
class TOONTANKS_API APawnMainMenu : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnMainMenu();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
