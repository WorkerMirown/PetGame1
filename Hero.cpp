#include "Box.h"
#include "Hero.h"
#include "Game.h"
#include "Goal.h"
#include "MainMenuRoom.h"
#include "MyKeyboard.h"
#include "TextureManager.h"
#include "SolidObject.h"
#include "ScoreManager.h"
#include "LevelMenuRoom.h"
#include "FadeOutAndChangeRoom.h"


Hero::Hero(float x, float y, int levelNumber)
	:SFMLObject(x, y, "hero_down", 2, 1),
	Steps(0),
	Font(new SFMLFont()),
	LevelNumber(levelNumber),
	WonGame(false)

{
	SetDepth(3);

}

Hero::~Hero()
{
	delete Font;
}



void Hero::Step()
{
	SFMLObject::Step();
	if (WonGame == true)
	{
		return;
	}
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Escape))
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
	}
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Right) || MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::D) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X() + SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetDirection(Right);
			SetSpeed(8.0f);
			SetAlarm(0, 8);
			GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_right"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectAtPosition<Box*>(X() + SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X() + (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{

					boxes[0]->SetSpeed(8);
					boxes[0]->SetDirection(Right);
					boxes[0]->SetAlarm(0, 8);
					SetImageSpeed(0.175f);
					SetSpeed(4.0f);
					SetDirection(Right);
					SetAlarm(0, 16);
					GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_right"));
				}
			}
		}
	}

	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Left) || MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::A) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X() - SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(8.0f);
			SetDirection(Left);
			SetAlarm(0, 8);
			GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_left"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectAtPosition<Box*>(X() - SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X() - (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{

					SetImageSpeed(0.175f);
					SetSpeed(4.0f);
					SetDirection(Left);
					SetAlarm(0, 16);
					boxes[0]->SetSpeed(8);
					boxes[0]->SetDirection(Left);
					boxes[0]->SetAlarm(0, 8);


					GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_left"));
				}
			}
		}
	}
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Up) || MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::W) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X(), Y() - SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(8.0f);
			SetDirection(Up);
			SetAlarm(0, 8);
			GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_up"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectAtPosition<Box*>(X(), Y() - SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X(), Y() - (SpriteHeight() << 1));
				if (solids.size() == 0)
				{

					SetImageSpeed(0.175f);
					SetSpeed(4.0f);
					SetDirection(Up);
					SetAlarm(0, 16);
					boxes[0]->SetImageSpeed(0.175f);
					boxes[0]->SetSpeed(8);
					boxes[0]->SetDirection(Up);
					boxes[0]->SetAlarm(0, 8);
					float xpos = X();
					float ypos = Y();

					GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_up"));
				}
			}
		}
	}
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Down) || MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::S) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X(), Y() + SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(8.0f);
			SetDirection(Down);
			SetAlarm(0, 8);
			GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_down"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectAtPosition<Box*>(X(), Y() + SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X(), Y() + (SpriteHeight() << 1));
				if (solids.size() == 0)
				{

					SetImageSpeed(0.175f);
					SetSpeed(4.0f);
					SetDirection(Down);
					SetAlarm(0, 16);
					boxes[0]->SetSpeed(8);
					boxes[0]->SetDirection(Down);
					boxes[0]->SetAlarm(0, 8);
					float xpos = X();
					float ypos = Y();

					GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_down"));
				}
			}
		}
	}

}

void Hero::OnAlarm(int alarm)
{
	if (alarm == 0)
	{
		SetImageSpeed(0.0f);
		SetSpeed(0.0f);
		Steps++;

		bool victory = true;
		std::vector<Goal*> goals = GetAllGameObjectOfType<Goal*>();

		for (Goal* g : goals)
		{
			std::vector<Box*> boxes = GetAllGameObjectAtPosition<Box*>(g->X(), g->Y());
			if (boxes.size() != 1)
			{
				victory = false;
				break;
			}
		}
		WonGame |= victory;
		if (victory == true && Alarm(1) < 0)
		{
			SetAlarm(1, 60);
			ScoreManager::GetInstance()->SaveScore(LevelNumber, Steps);

			//Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new LevelMenuRoom());
		}
	}
	if (alarm == 1)
	{
		Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new LevelMenuRoom));
	}
}

void Hero::Draw()
{
	Font->Print(5, 5, "STEPS " + std::to_string(Steps), sf::Color::Green);
	//224, 194, 131
	SFMLObject::Draw();
	if (WonGame == true)
	{
		Font->Print(350, 75, "Level Complete!", sf::Color::White, 3, 3);
	}

}