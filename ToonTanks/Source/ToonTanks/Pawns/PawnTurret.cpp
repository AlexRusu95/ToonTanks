// Alex Rusu 2021 - Toon Tanks


#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnTurret::CheckFireCondition() 
{
    // if player == null || is dead then bail
    if (!PlayerPawn) {return;}
    // if player is in range then fire
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        // Fire
        UE_LOG(LogTemp, Warning, TEXT("Fire()"));
    }
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if (!PlayerPawn) {return 0.0f;}

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}