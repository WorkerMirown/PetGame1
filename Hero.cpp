#include "Hero.h"
#include "MyKeyboard.h"

Hero::Hero(float x, float y)
	:SFMLObject(x, y, "Hero")
{
	SetSpeed(0.0f);
}

void Hero::Step()
{
	SFMLObject::Step();

	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Right))
	{
		SetSpeed(2.0f);
		SetDirection(Direction() - 2);
	}	
	if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Left))
	{
		SetSpeed(2.0f);
		SetDirection(Direction() + 2);
	}
	if (MyKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Up))
	{
		SetDirection(Direction()+90);
	}	
	if (MyKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Down))
	{
		SetDirection(Direction()-90);
	}
	if (MyKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Space))
	{
		SetAlarm(0, 1);
	}
	if (MyKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Num1))
	{
		SetDepth(Depth()+1);
	}

}

void Hero::OnAlarm(int alarm)
{
	SetX(XStart());
	SetY(YStart());
	SetSpeed(0.0f);
}
