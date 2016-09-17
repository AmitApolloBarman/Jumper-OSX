// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "CameraZoom.h"


// Sets default values
ACameraZoom::ACameraZoom() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    DesiredIntensity = 3000.0f;
    
    PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
    PointLight1->Intensity = DesiredIntensity;
    PointLight1->bVisible = true;
    RootComponent = PointLight1;
    
    Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
    Sphere1->InitSphereRadius(250.0f);
    Sphere1->SetupAttachment(RootComponent);
}

void ACameraZoom::OnOverlapBegin(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
    if (OtherActor && (OtherActor != this) && OtherComp) {
        ToggleLight();
    }
}

void ACameraZoom::OnOverlapEnd(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
    if (OtherActor && (OtherActor != this) && OtherComp) {
        ToggleLight();
    }
}

void ACameraZoom::ToggleLight() {
    PointLight1->ToggleVisibility();
}

// Called when the game starts or when spawned
void ACameraZoom::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ACameraZoom::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}

