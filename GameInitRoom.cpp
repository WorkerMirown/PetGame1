#include "GameInitRoom.h"
#include "TextureManager.h"
#include "GameLevelRoom.h"

GameInitRoom::GameInitRoom()
{
	TextureManager::GetInstanse()->AddTexture("Hero", "assets/Hero.png");
	TextureManager::GetInstanse()->AddTexture("Goal", "assets/Goal.png");
	TextureManager::GetInstanse()->AddTexture("Box", "assets/Box.png");
	TextureManager::GetInstanse()->AddTexture("Wall", "assets/Wall.png");
	TextureManager::GetInstanse()->AddTexture("FloarBlack", "assets/FloarBlack.png");
	TextureManager::GetInstanse()->AddTexture("Tileset", "assets/Tileset.png");
	
}

void GameInitRoom::Step()
{
	ChangeRoom(new GameLevelRoom("./levels/level.txt", 1));
}