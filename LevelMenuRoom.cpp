#include "LevelMenuRoom.h"
#include "MainMenuRoom.h"
#include "LVLMenuBackground.h"
#include "SFMLButton.h"
#include "Game.h"
#include "GameLevelRoom.h"
#include "SFMLFadeIn.h"
#include "FadeOutAndChangeRoom.h"
#include "MyKeyboard.h"

void PlayLevel001()
{
	///Уровень 1
	Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new GameLevelRoom("./levels/level.txt", 1)));
}
void PlayLevel002()
{
	///Уровень 2
	Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new GameLevelRoom("./levels/level1.txt", 2)));
}
void PlayLevel003()
{
	///Уровень 3
	Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new GameLevelRoom("./levels/level2.txt", 3)));
}
void PlayLevel004()
{
	///Уровень 4
	Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new GameLevelRoom("./levels/level3.txt", 4)));
}
void PlayLevel005()
{
	///Уровень 4
	Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new GameLevelRoom("./levels/level4.txt", 5)));
}

void MainMenu()
{
	/// Возврат в Main меню
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
}

LevelMenuRoom::LevelMenuRoom()
	:Room(),
	Font(new SFMLFont())
{
	
	InstanceCreate(new LVLMenuBackground(0, 0));
	

	//Step X+=130;
	InstanceCreate(new SFMLButton(400, 128, "NumBUtton", PlayLevel001));

	InstanceCreate(new SFMLButton(530, 128, "NumBUtton", PlayLevel002));

	InstanceCreate(new SFMLButton(660, 128, "NumBUtton", PlayLevel003));
	InstanceCreate(new SFMLButton(790, 128, "NumBUtton", PlayLevel004));
	InstanceCreate(new SFMLButton(920, 128, "NumBUtton", PlayLevel005));

	InstanceCreate(new SFMLButton(720, 512, "ExitBUtton", MainMenu)); // QUIT_Game
	
}

LevelMenuRoom::~LevelMenuRoom()
{
	delete Font; 
}
void LevelMenuRoom::Draw()
{
	Room::Draw(); // сначала отрисуй всех потомков
	Font->Print(433, 177, "01", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(563, 177, "02", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(693, 177, "03", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(823, 177, "04", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(953, 177, "05", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
}
