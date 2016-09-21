// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "ZoomingCamera.h"


// Sets default values for this component's properties
UZoomingCamera::UZoomingCamera()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}

// Method itself (Note the parameters)
void UZoomingCamera::OnPickup()
{
    APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
    PController->ConsoleCommand(TEXT("fov 95"), true);
}

// Called when the game starts
void UZoomingCamera::BeginPlay()
{
	Super::BeginPlay();
    APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if( PController )
        PController->ConsoleCommand(TEXT("fov 107"), true);
	
}

// Called every frame
void UZoomingCamera::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
    
	// ...
}

