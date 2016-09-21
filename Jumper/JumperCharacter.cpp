// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "JumperCharacter.h"

AJumperCharacter::AJumperCharacter()
{
    isCrouch = false;
    isTalking = false;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(30.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
    CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    SideViewCameraComponent->SetupAttachment(CameraBoom);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
    GetCharacterMovement()->bNotifyApex = true;
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
    GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
    isAir = false;
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
void AJumperCharacter::DecrementSkill()
{
}

// Input
void AJumperCharacter::ToggleCrouch()
{
    // If we are crouching then CanCrouch will return false. If we cannot crouch then calling Crouch() wont do anything
    if( CanCrouch() == true )
    {
        isCrouch = true;
        Crouch();
    }
    else
    {
        isCrouch = false;
        UnCrouch();
    }
}

void AJumperCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAxis("MoveRight", this, &AJumperCharacter::MoveRight);
    InputComponent->BindTouch(IE_Pressed, this, &AJumperCharacter::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AJumperCharacter::TouchStopped);
}

void AJumperCharacter::MoveRight(float Value)
{
	// add movement in that direction
    if (!isTalking)
        AddMovementInput(FVector(0.f,-1.f,0.f), Value);
    else
        AddMovementInput(FVector(0.f,0.f,0.f), Value);
}

void AJumperCharacter::NotifyJumpApex() {
    Super::NotifyJumpApex();
}

void AJumperCharacter::Jump() {
    Super::Jump();
    isAir = true;
}

void AJumperCharacter::StopJumping() {
    Super::StopJumping();
    isAir = false;
}
void AJumperCharacter::Falling() {
    Super::Falling();
}

void AJumperCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
    /* Touching the screen */
}

void AJumperCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
    /* Let go of touching the screen */
}
