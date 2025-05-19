#pragma once
#include "Room.h"
#include "SFMLFont.h"


class LevelMenuRoom : public Room
{
public:
	LevelMenuRoom();
	~LevelMenuRoom();

	void Draw() override;

private: 
	SFMLFont* Font;
};

