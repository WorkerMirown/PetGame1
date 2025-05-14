#pragma once
#include "Room.h"
class GameLevelRoom: public Room
{ 
public:
	GameLevelRoom(const std::string& filename, int levelNumber);


private:
	std::vector<SFMLObject> objects;
	int LevelNumber;
	
};

