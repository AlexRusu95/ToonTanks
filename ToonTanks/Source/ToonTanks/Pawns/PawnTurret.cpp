// Alex Rusu 2021 - Toon Tanks


#include "ToonTanks/Pawns/PawnTurret.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void APawnTurret::HandleDestruction() 
{
        Super::HandleDestruction();
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange) { return; }

    RotateTurret(PlayerPawn->GetActorLocation());

}

void APawnTurret::CheckFireCondition() 
{
    // if player == null || is dead then bail
    if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive()) {return;}
    // if player is in range then fire
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }
}

void APawnTurret::DrawDebugLineInGame() 
{
    FVector PlayerLocation = GetActorLocation();
	FRotator PlayerRotation = GetActorRotation();
    float Reach = FireRange;
	FVector LineTraceEnd = PlayerLocation + PlayerRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerLocation,
		LineTraceEnd,
		FColor(0, 0, 255),
		false,
		0.f,
		0,
		2.f
	);

}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if (!PlayerPawn) {return 0.0f;}

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}