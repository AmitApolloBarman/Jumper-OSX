// © 2016 Apollo Software, All rights reserved.

#pragma once

/**
 * 
 */
class JUMPER_API GameHelper
{
public:
	GameHelper();
	~GameHelper();
    float xLerp (float mMin, float mMax, float mFactor, float value);
    float IncrementLerp(float x, float v);
};
