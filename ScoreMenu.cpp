#include "ScoreMenu.h"
#include "MainMenuRoom.h"
#include "LVLMenuBackground.h"
#include "SFMLButton.h"
#include "Game.h"
#include "GameLevelRoom.h"
#include "LevelScoreMenu.h" 
#include "MyKeyboard.h"
#include "SFMLButton.h"

void ScoreLevel001()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelScoreMenu(1));
}
void ScoreLevel002()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelScoreMenu(2));
}
void ScoreLevel003()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelScoreMenu(3));
}
void ScoreLevel004()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelScoreMenu(4));
}
void ScoreLevel005()
{
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelScoreMenu(5));
}


void ReturnToMainMenu()
{
	/// Возврат в Main меню
	Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
}

ScoreMenu::ScoreMenu()
	:Room(),
	Font(new SFMLFont())
{

	InstanceCreate(new LVLMenuBackground(0, 0));

	InstanceCreate(new SFMLButton(400, 128, "NumBUtton", ScoreLevel001));

	InstanceCreate(new SFMLButton(530, 128, "NumBUtton", ScoreLevel002));

	InstanceCreate(new SFMLButton(660, 128, "NumBUtton", ScoreLevel003));
	InstanceCreate(new SFMLButton(790, 128, "NumBUtton", ScoreLevel004));
	InstanceCreate(new SFMLButton(920, 128, "NumBUtton", ScoreLevel005));

	InstanceCreate(new SFMLButton(720, 512, "ExitBUtton", ReturnToMainMenu)); // QUIT_Game

}

ScoreMenu::~ScoreMenu()
{
	delete Font;
}
void ScoreMenu::Draw()
{
	Room::Draw(); 
	Font->Print(433, 177, "01", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(563, 177, "02", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(693, 177, "03", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(823, 177, "04", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);
	Font->Print(953, 177, "05", sf::Color::Color(224, 194, 131, 255), 2.175, 2.175);

}
