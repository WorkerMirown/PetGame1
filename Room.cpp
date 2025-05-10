#include "Game.h"
#include "Room.h"

Room::Room()
	:Objects()
{
}

Room::~Room()
{
	for (SFMLObject* o : Objects)
	{
		delete o;
	}
	Objects.clear();
}

void Room::Step()
{
	for (SFMLObject* o : Objects)
	{
		o->Step();
	}

}

void Room::Draw()
{
	for (SFMLObject* o : Objects)
	{
		o->Draw();
	}
}

void Room::InstanceCreate(SFMLObject* Object)
{
	Objects.push_back(Object);
}

void Room::ChangeRoom(Room* NextRoom)
{
	Game::GetInstance()->ChangeRoom(NextRoom);
}
