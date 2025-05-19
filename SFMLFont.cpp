#include "SFMLFont.h"
#include "SFMLObject.h"
#include "Game.h"

SFMLFont::SFMLFont(const std::string& resource)
	: SFMLObject(1, 1, resource, 16, 16)
{
}

void SFMLFont::Print(
			int x,
			int y,
			const std::string& text,
			sf::Color tint,
			float xScale,
			float yScale
)
{
	GetSprite()->setScale(xScale, yScale);
	GetSprite()->setColor(tint);

	GetSprite()->setPosition(x, y);
	GetSprite()->setScale(xScale, yScale);
	GetSprite()->setColor(tint);
	for (const char& c : text)
	{
		SetImageIndex(static_cast<float>(c));
		int tileX = static_cast<int>(ImageIndex()) % VerticalFrames;
		int tileY = static_cast<int>(ImageIndex()) / HorizontalFrames;
		Sprite->setTextureRect(sf::IntRect(
			tileX * SpriteWidth(),
			tileY * SpriteHeight(),
			SpriteWidth(),
			SpriteHeight()
		));
		Game::GetInstance()->GetWindow()->draw(*Sprite);

		SetX(X() + (xScale * SpriteWidth()));
		x += static_cast<int>(SpriteWidth() * xScale);

	}
}
