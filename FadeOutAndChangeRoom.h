#pragma once
#include "SFMLObject.h"
#include "Game.h"
class FadeOutAndChangeRoom : public SFMLObject
{
public:
	FadeOutAndChangeRoom(Room* room);

	virtual void Step() override;

private:
	Room* NextRoom;
};

