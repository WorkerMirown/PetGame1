#include "FadeOutAndChangeRoom.h"

FadeOutAndChangeRoom::FadeOutAndChangeRoom(Room* room)
	:SFMLObject(0, 0, "1x1black"),
	NextRoom(room)
{
	GetSprite()->setScale(Game::GetInstance()->GetWindowResolution().x, Game::GetInstance()->GetWindowResolution().y);
	SetDepth(100);
	sf::Color color = GetSprite()->getColor();
	color.a = 0;
	GetSprite()->setColor(color);
}

void FadeOutAndChangeRoom::Step()
{
	sf::Color color = GetSprite()->getColor();
	color.a += 2;
	if (color.a > 253)
	{
		Game::GetInstance()->ChangeRoom(NextRoom);
	}
	GetSprite()->setColor(color);
}
