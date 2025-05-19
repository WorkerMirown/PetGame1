#pragma once
#include <iostream>
#include <vector>
#include "SFMLObject.h"
class SFMLObject;



class Room
{
public:
	Room();

	virtual ~Room();

	virtual void Step();
	virtual void Draw();
	
	void InstanceCreate(SFMLObject* Object);
	void ChangeRoom(Room* NextRoom);

	bool IsLevelComplete();

	bool IsLevelCompleted() ;
	void SetLevelCompleted(bool status);

	template <typename T>
	std::vector<T> GetAllGameObjectAtPosition(float x, float y);
	
	template <typename T>
	std::vector<T> GetAllGameObjectOfType();

private:
	std::vector<SFMLObject *> Objects;
	bool levelCompleted = false;

};


template<typename T>
inline std::vector<T> Room::GetAllGameObjectAtPosition(float x, float y)
{
	std::vector<T> obj;
	for (SFMLObject* o : Objects)
	{
		T casted = dynamic_cast<T>(o);
		if (casted != nullptr && o->SFMLObject::IsPointWithinSpriteBounds(x, y) == true)
		{
			obj.push_back(casted);
		}
	}
	return obj;
}

template<typename T>
inline std::vector<T> Room::GetAllGameObjectOfType()
{
	std::vector<T> obj;
	for (SFMLObject* o : Objects)
	{
		T casted = dynamic_cast<T>(o);
		if (casted != nullptr)
		{
			obj.push_back(casted);
		}
	}
	return obj;
}
