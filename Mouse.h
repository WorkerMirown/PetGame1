#pragma once
#include <SFML/Graphics.hpp>


class Mouse
{
public:
	static Mouse* GetInstance();

	sf::Vector2i GetMousePosition();
	bool IsBottonUp(sf::Mouse::Button Button);
	bool IsBottonPressed(sf::Mouse::Button Button);
	bool IsBottonDown(sf::Mouse::Button Button);
	bool IsBottonRelease(sf::Mouse::Button Button);

	void Update();

private:
	Mouse();

	static Mouse* Instance;

	bool Current[15];
	bool Previos[15];
};

