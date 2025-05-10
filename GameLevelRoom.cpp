#include <fstream>
#include <string>
#include "Box.h"
#include "Hero.h"
#include "Goal.h"
#include "Wall.h"
#include "GameLevelRoom.h"

GameLevelRoom::GameLevelRoom()
	:Room()
{
	std::ifstream file("level001.txt");
	if (file.fail())
	{
		int g = 0;
	}
	while (file.eof() == false)
	{
		std::string name;
		file >> name;
		int f = 0;
	}



	file.close();
}
