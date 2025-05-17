#include "LevelMenuRoom.h"
#include "MainMenuRoom.h"
#include "LVLMenuBackground.h"
#include "SFMLButton.h"
#include "Game.h"
#include "GameLevelRoom.h"
#include "MyKeyboard.h"

void PlayLevel001()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new GameLevelRoom("./levels/level.txt", 1));
}
void PlayLevel002()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new GameLevelRoom("./levels/level1.txt", 1));
}
void PlayLevel003()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new GameLevelRoom("./levels/level2.txt", 1));
}

void MainMenu()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
}

LevelMenuRoom::LevelMenuRoom()
	:Room()
{
	InstanceCreate(new LVLMenuBackground(0, 0));
	InstanceCreate(new SFMLButton(420, 128, "NumBUtton", PlayLevel001));
	InstanceCreate(new SFMLButton(570, 128, "NumBUtton", PlayLevel002));
	InstanceCreate(new SFMLButton(700, 128, "NumBUtton", PlayLevel003));
	InstanceCreate(new SFMLButton(720, 512, "ExitBUtton", MainMenu)); // QUIT_Game

}