// Alex Rusu 2021 - Toon Tanks


#include "ToonTanks/PlayerControllers/PlayerControllerBase.h"


void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled) 
{
    if (SetPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
    }
    else
    {
        GetPawn()->DisableInput(this);
    }

    bShowMouseCursor = SetPlayerEnabled;
}
