// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "JumperCharacter.h"
#include "GameController.h"
#include "GameHelper.h"

GameHelper gh;
float DeltaSpeed= 0.0f;
// Sets default values
AGameController::AGameController() {
    DeltaSpeed= 0.0f;
    ptr->isAir = &isAir;
    ptr->skill = &skill;
    ptr->life  = &life;
    ptr->time  = &time;
    ptr->fieldOfView = &fieldOfView;
    InitializeValues();
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AGameController::AGameController(bool x) {
    ptr->isAir = &isAir;
    ptr->skill = &skill;
    ptr->life  = &life;
    ptr->time  = &time;
    ptr->fieldOfView = &fieldOfView;
    InitializeValues();
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = x;
}

void AGameController::FinishView() {
    APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
    PController->DisableInput(PController);
    showUI = false;
    PController->ActivateTouchInterface(NULL);
}

void AGameController::InitializeValues() {
    *ptr->life  = START_LIFE;
    *ptr->isAir  = false;
    *ptr->time  = MAX_TIME/5;
    *ptr->fieldOfView  = START_FOV;
    *ptr->skill = START_SKILL;
}
// Called when the game starts or when spawned
void AGameController::BeginPlay() {
	Super::BeginPlay();
    beginPlay = true;
    showUI = false;
	totalKills = 0;
    life = *ptr->life;
    time = *ptr->time;
    skill= *ptr->skill;
    isAir = *ptr->isAir;
    fieldOfView = *ptr->fieldOfView;
	//*ptr->fieldOfView = ToggleCamera(*ptr->fieldOfView);
}
void AGameController::xLerp (float mMin, float mMax, float mFactor, float value) {
    dayAndNight = gh.xLerp(mMin,mMax,mFactor + fabs(DeltaSpeed/2000),value);
    /*
    FString str = FString::SanitizeFloat(fabs(DeltaSpeed) + 0.5f);
    dayAndNight = fabs(DeltaSpeed) + 0.25f;
    bottomMessage = "" + str + "";*/
}
// Called every frame
void AGameController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    RunningTime += DeltaTime;
    if (!beginGame || pauseGame)
        return;
    if (BeginLogic())
        return;
    FovLogic();
    SkillLogic();
    LifeLogic();
    TimeLogic();
    DeltaSpeed = (FMath::Sin(RunningTime));
    if (!beginPlay && *ptr->time<=0) {
        *ptr->life -= LIFE_INC * 20;
    }
}

void AGameController::TimeLogic() {
    if (*ptr->time>0)
        *ptr->time -= (TIME_DEC/2);
    if (*ptr->time <= MAX_TIME && doTimeLogic)
        *ptr->time += LIFE_INC_BEG/10.0f;
}

void AGameController::LifeLogic() {
    if (beginPlay && *ptr->life<=0)
        FinishView();
    if (!beginPlay && *ptr->life<=MAX_LIFE && *ptr->life>0 && doLifeLogic)
        *ptr->life += LIFE_INC * 15;
    if (!beginPlay && *ptr->life<=MAX_LIFE && *ptr->life>0 && !doLifeLogic)
        *ptr->life += LIFE_INC/2;
}

void AGameController::SkillLogic() {
    AJumperCharacter *Avatar = Cast<AJumperCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
    if (Avatar) {
        if (!Avatar->isAir && !beginPlay && *ptr->skill<=MAX_SKILL && doSkillLogic)
            *ptr->skill += SKILL_INC*5;
        if (!Avatar->isAir && !beginPlay && *ptr->skill<=MAX_SKILL)
            *ptr->skill += SKILL_INC/2;
        else if (Avatar->isAir && !beginPlay && *ptr->skill>0) {
            if (!Avatar->isCrouch)
                *ptr->skill -= SKILL_DEC * 3.5f;
        }
    }
}

bool AGameController::BeginLogic() {
    if (beginPlay) {
        if (*ptr->time <= MAX_TIME)
            *ptr->time += LIFE_INC_BEG*2;
        if (*ptr->life <= MAX_LIFE)
            *ptr->life += LIFE_INC_BEG/2;
        if (*ptr->skill <= MAX_SKILL/2)
            *ptr->skill += SKILL_INC_BEG;
        if (fieldOfView<MAX_FOV)
            *ptr->fieldOfView = ToggleCamera(*ptr->fieldOfView + FOV_INCR_DEC);
        else
            beginPlay = false;
        return true;
    }
    return false;
}

void AGameController::FovLogic() {
	if (*ptr->fieldOfView >= MIN_FOV && makeSmaller)
		*ptr->fieldOfView = ToggleCamera(*ptr->fieldOfView - (FOV_INCR_DEC * 1.5f));
	else
        makeSmaller = false;
	
    if (*ptr->fieldOfView <= MAX_FOV && makeBigger)
		*ptr->fieldOfView = ToggleCamera(*ptr->fieldOfView  + (FOV_INCR_DEC * 1.5f));
	else
        makeBigger = false;
}

void AGameController::ZoomOut() {
    makeSmaller = true;
    makeBigger = false;
}

void AGameController::ZoomIn() {
    makeSmaller = false;
    makeBigger = true;
}

void AGameController::ZoomCameraFOV(float x) {
    if (*ptr->fieldOfView >= x)
        *ptr->fieldOfView = ToggleCamera(*ptr->fieldOfView - FOV_INCR_DEC);
}

void AGameController::UnZoomCameraFOV(float x) {
    if (*ptr->fieldOfView <= x)
        *ptr->fieldOfView = ToggleCamera(*ptr->fieldOfView + FOV_INCR_DEC);
}

float AGameController::ToggleCamera(float x) {
    FString str = FString::SanitizeFloat(x);
        APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
        PController->ConsoleCommand(TEXT("fov " + str), true);
    return x;
}

void AGameController::IncrementKill(int x) {
	totalKills = totalKills + 1;
	FString str = FString::FromInt(totalKills);
    FString str2 = FString::FromInt(totalEnemies);
    if (totalKills==1)
        str = str + " kill";
    else
        str = str + " kills ";
    
    bottomMessage = str;
}

void AGameController::IncrementObjective(int x) {
	totalObjectives += 1;
}

void AGameController::DecrementLife(float g) {
    *ptr->life -= g;
}
