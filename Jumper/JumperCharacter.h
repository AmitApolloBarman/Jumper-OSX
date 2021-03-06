// © 2016 Apollo Software, All rights reserved.
#pragma once
#include "GameFramework/Character.h"
#include "JumperCharacter.generated.h"

// State Machine Mode for Hero
UENUM(BlueprintType)
enum class HeroMode : uint8
{
    Attack      UMETA(DisplayName="Attack"),
    Dead        UMETA(DisplayName="Dead"),
    Hit         UMETA(DisplayName="Hit"),
    Idle        UMETA(DisplayName="Idle"),
    Jump        UMETA(DisplayName="Jump"),
    Talk        UMETA(DisplayName="Talk"),
    Taunt       UMETA(DisplayName="Taunt"),
    Walk        UMETA(DisplayName="Walk")
};

UCLASS(config=Game)
class AJumperCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
    virtual void NotifyJumpApex() override;
    virtual void Falling() override;
    virtual void Jump() override;
    virtual void StopJumping() override;

public:

    AJumperCharacter();
    void DecrementSkill();
    void ToggleCrouch();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumperCharacter")
    FVector2D ViewportSize = FVector2D(0,360);
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumperCharacter")
    FVector2D ViewportCenter =  FVector2D(ViewportSize.X/2, ViewportSize.Y/2);
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumperCharacter")
    bool isTalking;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumperCharacter")
    bool isAir;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumperCharacter")
    bool isCrouch;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumperCharacter")
    HeroMode Mode = HeroMode::Idle;
    
    /** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
