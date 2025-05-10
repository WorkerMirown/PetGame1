#pragma once
#include "Room.h"
class GameLevelRoom: public Room
{ 
public:
	GameLevelRoom();
	bool loadFromFile(const std::string& filename);
	void draw(sf::RenderWindow& window);
private:
	std::vector<SFMLObject> objects;
	const int TILE_SIZE = 60; // размер клетки
};

