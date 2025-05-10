#pragma once
#include <SFML/Graphics.hpp>

class MyKeyboard
{

public:
	static MyKeyboard* GetInstance();

	bool IsKeyUp(sf::Keyboard::Key Key);
	bool IsKeyPressed(sf::Keyboard::Key Key);
	bool IsKeyDown(sf::Keyboard::Key Key);
	bool IsKeyReleased(sf::Keyboard::Key Key);
	
	void Update();

private:
	MyKeyboard();

	static MyKeyboard* Instance;
	bool Current[125];
	bool Previous[125];

};

