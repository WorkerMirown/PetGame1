#include "SFMLObject.h"
#include "Game.h"
#include "TextureManager.h"

SFMLObject::SFMLObject(int x, int y, const std::string& resource)
	: Sprite(new sf::Sprite())
{
	if (resource != "")
	{
		sf::Texture* Texture =
			TextureManager::GetInstanse()->GetTexture(resource);
		Sprite->setTexture(*Texture);
		Sprite->setPosition(x, y);
	}
}

SFMLObject::~SFMLObject()
{
	delete Sprite;
	Sprite = nullptr;
}

void SFMLObject::Step()
{
}

void SFMLObject::Draw()
{
	if (Sprite != nullptr)
	{
		Game::GetInstance()->GetWindow()->draw(*Sprite);
	}
}

sf::Sprite* SFMLObject::GetSprite()
{
	return Sprite;
}
//void SFMLObject::setPosition(float x, float y) {
//	Sprite->setPosition(x, y);
//}