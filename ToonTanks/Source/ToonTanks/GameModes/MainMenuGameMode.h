// Alex Rusu 2021 - Toon Tanks

#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/GameModes/ToonTankGameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AMainMenuGameMode : public AToonTankGameModeBase
{
	GENERATED_BODY()

private:

protected:
	virtual void BeginPlay() override;
	
};
