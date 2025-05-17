#include "Box.h"
#include "Hero.h"
#include "Game.h"
#include "Goal.h"
#include "MainMenuRoom.h"
#include "MyKeyboard.h"
#include "TextureManager.h"
#include "SolidObject.h"



Hero::Hero(float x, float y)
	:SFMLObject(x, y, "hero_down", 2, 1)
{
	SetDepth(3);

}

//Hero:~()
//{
//
//}

void Hero::Step()
{
	SFMLObject::Step();
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Escape))
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
	}
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Right) && (Alarm(0)< 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject *>(X()+SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetDirection(0);
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
				boxes[0]->SetDirection(0);
				boxes[0]->SetAlarm(0, 8);
				SetImageSpeed(0.175f);
				SetSpeed(4.0f);
				SetDirection(0);
				SetAlarm(0, 16);
				GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_right"));
			}
		}
	}
}
	
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Left) && (Alarm(0)< 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject *>( X() - SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(8.0f);
			SetDirection(180);
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
				SetSpeed(2.0f);
				SetDirection(180);
				SetAlarm(0, 32);
				boxes[0]->SetSpeed(8);
				boxes[0]->SetDirection(180);
				boxes[0]->SetAlarm(0, 8);
				
				
				GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_left"));
			}
		}
		}
	}	

	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Up) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X() , Y() - SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(8.0f);
			SetDirection(90);
			SetAlarm(0, 8);
			GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_up"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectAtPosition<Box*>(X(), Y() - SpriteHeight());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X(), Y()-(SpriteHeight()<<1));
				if (solids.size() == 0)
				{

					SetImageSpeed(0.175f);
					SetSpeed(2.0f);
					SetDirection(90);
					SetAlarm(0, 32);
					boxes[0]->SetImageSpeed(0.175f);
					boxes[0]->SetSpeed(8);
					boxes[0]->SetDirection(90);
					boxes[0]->SetAlarm(0, 8);
					float xpos = X();
					float ypos = Y();

					GetSprite()->setTexture(*TextureManager::GetInstanse()->GetTexture("hero_up"));
				}
			}
		}
	}
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Down) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectAtPosition<SolidObject*>(X(), Y() + SpriteHeight());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(8.0f);
			SetDirection(270);
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
					SetSpeed(2.0f);
					SetDirection(270);
					SetAlarm(0, 32);
					boxes[0]->SetSpeed(8);
					boxes[0]->SetDirection(270);
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
	SetImageSpeed(0.0f);
	SetSpeed(0.0f);
	Steps++;

	/*bool victory = true;
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
	if (victory == true)
	{
		int f = 0;
	}*/
	
}
