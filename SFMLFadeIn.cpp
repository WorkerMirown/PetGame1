#include "SFMLFadeIn.h"
#include "Game.h"

SFMLFadeIn::SFMLFadeIn()
	: SFMLObject(0,0, "1x1black",1,1)
{
	GetSprite()->setScale(Game::GetInstance()->GetWindowResolution().x, Game::GetInstance()->GetWindowResolution().y);
	SetDepth(100);
}

void SFMLFadeIn::Step()
{
	sf::Color color = GetSprite()->getColor();
	if (color.a > 2)
	{
		color.a -= 5;
	}
	else
	{
		color.a = 0;
	}
	GetSprite()->setColor(color);
}
