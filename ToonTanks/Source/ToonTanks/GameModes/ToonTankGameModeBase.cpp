// Alex Rusu 2021 - Toon Tanks


#include "ToonTanks/GameModes/ToonTankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "ToonTanks/PlayerControllers/PlayerControllerBase.h"
#include "Kismet/GameplayStatics.h"


void AToonTankGameModeBase::BeginPlay() 
{
        Super::BeginPlay();

    // Get references and game win/lose conditions

    
    // Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
    HandleGameStart();
}

void AToonTankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of Actor died. If turret, tally, if player -> go to lose condition
    if (DeadActor == PlayerTank)
    {
        PlayerTank->HandleDestruction();
        HandleGameOver(false);

        if (PlayerControllerRef)
        {
            PlayerControllerRef->SetPlayerEnabledState(false);
        }
    }
    else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
    {
        DestroyedTurret->HandleDestruction();
        if (--TargetTurrets == 0)
        {
            HandleGameOver(true);
        }
    }
}

void AToonTankGameModeBase::HandleGameStart() 
{
    TargetTurrets = GetTargetTurretCount();
    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
    PlayerControllerRef = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));

    GameStart();
    if (PlayerControllerRef)
        {
            PlayerControllerRef->SetPlayerEnabledState(false);

            FTimerHandle PlayerEnableHandle;
            FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerControllerRef, &APlayerControllerBase::SetPlayerEnabledState, true);                                             
            GetWorld()->GetTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
        }
}

void AToonTankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result
    // call blueprint version GameOver(bool)
    GameOver(PlayerWon);
}

int32 AToonTankGameModeBase::GetTargetTurretCount() 
{
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
    return TurretActors.Num();
}
