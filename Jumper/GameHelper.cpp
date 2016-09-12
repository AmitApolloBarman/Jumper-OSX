// © 2016 Apollo Software, All rights reserved.

#include "Jumper.h"
#include "GameHelper.h"

bool goBackwards = true;
bool goForwards = false;

GameHelper::GameHelper()
{
    goBackwards = true;
    goForwards = false;
}

GameHelper::~GameHelper()
{
    
}

float GameHelper::IncrementLerp(float x, float v) {
    return v+=x;
}

float GameHelper::xLerp (float mMin, float mMax, float mFactor, float value) {
    if (value>=mMin && goBackwards){
        value = IncrementLerp(-mFactor,value);
        if (value<=mMin) {
            goForwards = true;
            goBackwards = false;
        }
    } else if (goForwards && value<=mMax) {
        value = IncrementLerp(mFactor,value);
        if (value>=mMax) {
            goBackwards = true;
            goForwards = false;
        }
    }
    return value;
}