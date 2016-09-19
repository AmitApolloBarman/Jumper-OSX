// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "TriggerZoom.h"


// Sets default values
ATriggerZoom::ATriggerZoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ATriggerZoom::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
        ToggleCamera(90.0);
}

void ATriggerZoom::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
        ToggleCamera(107.0);
}
void ATriggerZoom::ToggleCamera(float x) {
    if (x >=107.0)
    {
        APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
        PController->ConsoleCommand(TEXT("fov 107"), true);
    }
    else
    {
        APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
        PController->ConsoleCommand(TEXT("fov 90"), true);
    }
}
// Called when the game starts or when spawned
void ATriggerZoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerZoom::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

