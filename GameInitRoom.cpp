#include "GameInitRoom.h"
#include "TextureManager.h"
#include "GameLevelRoom.h"

GameInitRoom::GameInitRoom()
{
	TextureManager::GetInstanse()->AddTexture("Hero", "Hero.png");
	TextureManager::GetInstanse()->AddTexture("Goal", "Goal.png");
	TextureManager::GetInstanse()->AddTexture("Box", "Box.png");
	TextureManager::GetInstanse()->AddTexture("Wall", "Wall.png");
	TextureManager::GetInstanse()->AddTexture("FloarBlack", "FloarBlack.png");
	
}

void GameInitRoom::Step()
{
	ChangeRoom(new GameLevelRoom());
}