#pragma once

#include <vector>
#include "SFMLObject.h"
#include "Room.h"


class Room
{
public:
	Room();

	virtual ~Room();

	virtual void Step();
	virtual void Draw();
	
	void InstanceCreate(SFMLObject* Object);
	void ChangeRoom(Room* NextRoom);

private:
	std::vector<SFMLObject*> Objects;
};

