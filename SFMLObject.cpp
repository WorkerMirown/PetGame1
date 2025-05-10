#include "SFMLObject.h"
#include "Game.h"
#include "TextureManager.h"

SFMLObject::SFMLObject(const std::string& resource)
	: Sprite(new sf::Sprite())
{
	if (resource != "")
	{
		sf::Texture* Texture =
			TextureManager::GetInstanse()->GetTexture(resource);
		Sprite->setTexture(*Texture);
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
