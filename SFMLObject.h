#pragma once
#include <SFML/Graphics.hpp>
class SFMLObject
{
public:
	SFMLObject(const std::string& resource= "");

	virtual ~SFMLObject();

	virtual void Step();
	virtual void Draw();
	void setPosition(float x, float y);

	sf::Sprite* GetSprite();

private:
	sf::Sprite* Sprite;
};

