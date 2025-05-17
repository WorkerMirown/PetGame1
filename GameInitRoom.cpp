#include "GameInitRoom.h"
#include "MainMenuRoom.h"
#include "TextureManager.h"
#include "GameLevelRoom.h"

GameInitRoom::GameInitRoom()
{
	//Font
	TextureManager::GetInstanse()->AddTexture("font", "Font1.png");
	
	//MainMenu
	TextureManager::GetInstanse()->AddTexture("main_menu_background", "assets/menu/GameMenu.png");
	TextureManager::GetInstanse()->AddTexture("ExitBUtton", "assets/menu/ExitBUtton.png");
	TextureManager::GetInstanse()->AddTexture("LvlsBUtton", "assets/menu/LvlsBUtton.png");
	TextureManager::GetInstanse()->AddTexture("PlayBUtton", "assets/menu/PlayBUtton.png");
	TextureManager::GetInstanse()->AddTexture("ScoreBUtton", "assets/menu/ScoreBUtton.png");
	TextureManager::GetInstanse()->AddTexture("NumBUtton", "assets/menu/NumBUtton.png");
	TextureManager::GetInstanse()->AddTexture("LVLMenu", "assets/menu/LVLMenu.png");


	//TextureOfObject
	TextureManager::GetInstanse()->AddTexture("Hero", "assets/Hero.png");
	TextureManager::GetInstanse()->AddTexture("Goal", "assets/Goal.png");
	TextureManager::GetInstanse()->AddTexture("Box", "assets/Box.png");
	TextureManager::GetInstanse()->AddTexture("Wall", "assets/Wall.png");
	TextureManager::GetInstanse()->AddTexture("FloarB", "assets/FloarBlack.png");
	TextureManager::GetInstanse()->AddTexture("FloarL", "assets/FloarLight.png");
	TextureManager::GetInstanse()->AddTexture("Tileset", "assets/Tileset.png");	

	//HeroMovement
	TextureManager::GetInstanse()->AddTexture("hero_left", "assets/hero_left.png");
	TextureManager::GetInstanse()->AddTexture("hero_right", "assets/hero_right.png");
	TextureManager::GetInstanse()->AddTexture("hero_up", "assets/hero_up.png");
	TextureManager::GetInstanse()->AddTexture("hero_down", "assets/hero_down.png");

}

void GameInitRoom::Step()
{
	ChangeRoom(new MainMenuRoom());
	
	
	//ChangeRoom(new GameLevelRoom("./levels/level.txt", 1));
}