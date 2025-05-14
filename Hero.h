#pragma once
#include "SFMLObject.h"

class Hero: public SFMLObject
{
public:
	Hero(float x, float y);
	
	virtual void Step() override;
	virtual void OnAlarm(int alarm) override;

};

