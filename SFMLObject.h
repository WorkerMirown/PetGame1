#pragma once
#include <SFML/Graphics.hpp>
class SFMLObject
{
public:
	SFMLObject(const std::string& resource= "");

	virtual ~SFMLObject();

	virtual void Step();
	virtual void Draw();

	sf::Sprite* GetSprite();

private:
	sf::Sprite* Sprite;
};

