// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "EnemyCharacter.h"

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
        case EnemyMode::Attack: break;
        case EnemyMode::Dead: break;
        case EnemyMode::Flee: break;
        case EnemyMode::Hit: break;
        case EnemyMode::Idle: break;
        case EnemyMode::Patrol: break;
        case EnemyMode::Pursue: break;
        case EnemyMode::Talk: break;
        case EnemyMode::Taunt: break;
        default:
            break;
    }
}

void AEnemyCharacter::SetMode(uint8 m) {
    if (Mode!=EnemyMode::Hit)
        switch (m) {
            case 0:SetMode(EnemyMode::Attack);  break;
            case 1:SetMode(EnemyMode::Dead);  break;
            case 2:SetMode(EnemyMode::Flee);  break;
            case 3:SetMode(EnemyMode::Hit);  break;
            case 4:SetMode(EnemyMode::Idle);  break;
            case 5:SetMode(EnemyMode::Patrol);  break;
            case 6:SetMode(EnemyMode::Pursue);  break;
            case 7:SetMode(EnemyMode::Talk);  break;
            case 8:SetMode(EnemyMode::Taunt);  break;
            default:SetMode(EnemyMode::Pursue);  break;
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
        SetMode(EnemyMode::Dead);
}

void AEnemyCharacter::MoveRight(float Value)
{
    // add movement in that direction
    AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AEnemyCharacter::MoveLeft(float Value)
{
    // add movement in that direction
    AddMovementInput(FVector(0.f,1.f,0.f), Value);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);
}

void AEnemyCharacter::DecrementLife(float g) {
    if (EnemyLife>0)
        EnemyLife = EnemyLife - g;
}

