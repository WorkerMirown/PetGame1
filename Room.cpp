#include "Game.h"
#include "Room.h"
#include "Box.h"
#include "Goal.h"
#include "MainMenuRoom.h"

Room::Room()
	:Objects()
{
	levelCompleted = false;
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
	for (int i = 0; i < Objects.size(); i++)
	{
		Objects[i]->Step();
	}

}

bool LessThanOperator(SFMLObject* lhs, SFMLObject* rhs)
{
	return lhs->Depth() < rhs->Depth();
}

void Room::Draw()
{
	std::sort(Objects.begin(), Objects.end(), LessThanOperator);

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



//bool Room::IsLevelCompleted() 
//{
//	return levelCompleted;
//}
//
//void Room::SetLevelCompleted(bool status)
//{
//	levelCompleted = status;
//}
