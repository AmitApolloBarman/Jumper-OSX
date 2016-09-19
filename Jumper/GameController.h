// © 2016 Apollo Software, All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "GameController.generated.h"

UCLASS()
class JUMPER_API AGameController : public AActor {
	GENERATED_BODY()
//#define clean(x) FString::SanitizeFloat(x)
//#define fori(x) for (int i=0; i<=x; i++)
	
public:	
	// Sets default values for this actor's properties
	AGameController();
    AGameController(bool x);
    struct GameSettings {
		float* life;
        float* skill;
		float* time;
		float* fieldOfView;
        bool*  isAir;
    };

    const float TIME_DEC = 0.00015f;
    const float SKILL_INC = 0.002f;
    const float SKILL_DEC = 0.0025f;
    const float LIFE_INC_BEG = 0.025f;
    const float LIFE_INC = 0.00025f;
    const float SKILL_INC_BEG = 0.02f;
    const float MAX_SKILL = 1.0f;
	const float MAX_LIFE = 1.0f;
	const float MAX_TIME = 1.0f;
	const float MAX_FOV = 100.0f;
	const float MIN_FOV = 90.0f;
	const float START_FOV = 85.0f;
	const float START_LIFE = 0.25f;
    const float START_SKILL = 0.25f;
	const float FOV_INCR_DEC = 1.0f;
	const float MAX_END_FOV = 65.0f;
	GameSettings _gameSettings;
	GameSettings* ptr = &_gameSettings;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool beginGame = false;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool pauseGame = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool beginPlay = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool isVR;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool isMobile;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool showUI;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool isPause;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool isCrouch;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool isDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool isAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
	FString textMessage = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    FString bottomMessage = "JUMPER";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    FString GameMessage = "";
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
	float life = 0.01f; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    float dayAndNight = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    int totalKills = 0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    int totalEnemies = 15;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
	int totalObjectives = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    float skill = 0.01f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    float time = 1.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    float fieldOfView = 107.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraController")
    bool makeBigger = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraController")
    bool makeSmaller = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool doLifeLogic = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool doSkillLogic = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameController")
    bool doTimeLogic = false;
    
    /** Toggles the camera zoom*/
    UFUNCTION(BlueprintCallable, Category = "CameraController")
    float ToggleCamera(float x);

    bool BeginLogic();
    void FovLogic();
    void TimeLogic();
    void SkillLogic();
    void LifeLogic();
    void FinishView();
    void InitializeValues();
    float IncrementLerp(float x,float v);
    UFUNCTION(BlueprintCallable, Category = "Lerp")
    void xLerp (float mMin, float mMax, float mFactor, float value);
    
    UFUNCTION(BlueprintCallable, Category = "Zoom")
    void ZoomCameraFOV(float x);
    UFUNCTION(BlueprintCallable, Category = "Zoom")
    void ZoomIn();
    UFUNCTION(BlueprintCallable, Category = "Zoom")
    void ZoomOut();
    
    UFUNCTION(BlueprintCallable, Category = "Zoom")
    void UnZoomCameraFOV(float x);
    
    UFUNCTION(BlueprintCallable, Category = "Player Kills")
	void IncrementKill(int x);
	
    UFUNCTION(BlueprintCallable, Category = "Player Objectives")
	void IncrementObjective(int x);
    
    UFUNCTION(BlueprintCallable,Category = "Player Life")
    void DecrementLife(float x);
private:
    float RunningTime = 0.0f;
};
