// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "EnemyCharacter.h"

/*
UENUM(BlueprintType)
enum class Modes : uint8
{
    Pursue      UMETA(DisplayName="Pursue"),
    Patrol      UMETA(DisplayName="Patrol"),
    Attack      UMETA(DisplayName="Attack"),
    Flee        UMETA(DisplayName="Fleeing"),
    Talk        UMETA(DisplayName="Talk"),
    Dead        UMETA(DisplayName="Dead"),
    Taunt       UMETA(DisplayName="Taunt")
};*/

// Sets default values
AEnemyCharacter::AEnemyCharacter() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay() {
	Super::BeginPlay();
    GetCharacterMovement()->MaxWalkSpeed = Speed;
    GetCapsuleComponent()->SetCapsuleRadius(Radius);
}

void AEnemyCharacter::ProcessMode(EnemyMode m) {
    switch (m) {
        case EnemyMode::Pursue: break;
        case EnemyMode::Patrol: break;
        case EnemyMode::Attack: break;
        case EnemyMode::Flee: break;
        case EnemyMode::Talk: break;
        case EnemyMode::Dead: break;
        case EnemyMode::Taunt: break;
        default:
            break;
    }
}

void AEnemyCharacter::SetMode(EnemyMode m) {
    Mode = m;
}

// Called every frame
void AEnemyCharacter::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
    if (EnemyLife<MAX_LIFE)
        EnemyLife = EnemyLife + LIFE_INC;
    ProcessMode(Mode);
    if (EnemyLife<=0)
        ProcessMode(EnemyMode::Dead);
}

void AEnemyCharacter::MoveChar(float DeltaTime) {
    FVector NewLocation = GetActorLocation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Y += DeltaHeight * Speed;
    //Scale our distance by a factor of 20
    RunningTime += DeltaTime;
    SetActorLocation(NewLocation, collide);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);

}

void AEnemyCharacter::DecrementLife(float g) {
    if (EnemyLife>0)
        EnemyLife = EnemyLife - g;
}

