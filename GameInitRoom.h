#pragma once
#include "Room.h"

class GameInitRoom : public Room
{
public:
	GameInitRoom();

	virtual void Step() override;
};

