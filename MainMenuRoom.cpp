#include "MainMenuRoom.h"
#include "MainMenuBackground.h"
#include "SFMLButton.h"
#include "GameLevelRoom.h"
#include "MyKeyboard.h"
#include "LevelMenuRoom.h"
#include "ScoreMenu.h"
#include "FadeOutAndChangeRoom.h"


void QuitGame()
{
	Game::GetInstance()->QuitGame();

}
void PlayGame()
{
	///Уровень 1
	Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new GameLevelRoom("levels/level.txt", 1)));
}
void LevelMenu()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelMenuRoom);
}
void OpenScoreMenu()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new ScoreMenu);
}



MainMenuRoom::MainMenuRoom()
	:Room()
{
	
	InstanceCreate(new MainMenuBackground(0,0));
	InstanceCreate(new SFMLButton(960, 192, "ScoreBUtton", OpenScoreMenu));
	InstanceCreate(new SFMLButton(720,512, "ExitBUtton", QuitGame)); // QUIT_Game
	InstanceCreate(new SFMLButton(640, 320, "LvlsBUtton", LevelMenu)); // 
	InstanceCreate(new SFMLButton(640, 128, "PlayBUtton", PlayGame));


}
