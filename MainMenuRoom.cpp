#include "MainMenuRoom.h"
#include "MainMenuBackground.h"
#include "SFMLButton.h"
#include "Game.h"
#include "GameLevelRoom.h"
#include "MyKeyboard.h"
#include "LevelMenuRoom.h"

void QuitGame()
{
	Game::GetInstance()->QuitGame();
}
void LevelMenu()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelMenuRoom);
}



MainMenuRoom::MainMenuRoom()
	:Room()
{
	
	InstanceCreate(new MainMenuBackground(0,0));
	InstanceCreate(new SFMLButton(720,512, "ExitBUtton", QuitGame)); // QUIT_Game
	InstanceCreate(new SFMLButton(640, 320, "LvlsBUtton", LevelMenu)); // Level 1
	//InstanceCreate(new SFMLButton(640, 128, "PlayBUtton", PlayLevel002)); // Level 2
	//InstanceCreate(new SFMLButton(960, 192, "ScoreBUtton", PlayLevel003)); // Level 3
}
