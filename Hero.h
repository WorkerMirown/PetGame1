#pragma once
#include "SFMLFont.h"
#include "SFMLObject.h"

class Hero: public SFMLObject
{
public:
	Hero(float x, float y, int levelNumber);
	~Hero();
	virtual void Step() override;
	virtual void OnAlarm(int alarm) override;
	virtual void Draw() override;

private:
	int Steps;
	SFMLFont* Font;
	int LevelNumber;
	bool victory;
	bool WonGame;
};

