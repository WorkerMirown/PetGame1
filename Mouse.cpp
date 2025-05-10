#include "Mouse.h"
#include "Game.h"

Mouse* Mouse::Instance = nullptr;

Mouse::Mouse()
{
	Update();
}

Mouse* Mouse::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new Mouse();
	}
	return Instance;
}

sf::Vector2i Mouse::GetMousePosition()
{
	return sf::Mouse::getPosition(*Game::GetInstance()->GetWindow());
}

bool Mouse::IsBottonUp(sf::Mouse::Button Button)
{
	return (Current[Button] == false && (Previos[Button] == false));
}

bool Mouse::IsBottonPressed(sf::Mouse::Button Button)
{
	return (Current[Button] == true && (Previos[Button] == false));
}

bool Mouse::IsBottonDown(sf::Mouse::Button Button)
{
	return (Current[Button] == true && (Previos[Button] == true));
}

bool Mouse::IsBottonRelease(sf::Mouse::Button Button)
{
	return (Current[Button] == false && (Previos[Button] == true));
}

void Mouse::Update()
{
	for (int i = 0; i < sf::Mouse::ButtonCount; ++i)
	{
		Previos[i] = Current[i];
		Current[i] = sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(i));
	}
}
