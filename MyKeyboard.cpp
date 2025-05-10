#include "MyKeyboard.h"

MyKeyboard* MyKeyboard::Instance = nullptr;

MyKeyboard::MyKeyboard()
{
    Update();
}


MyKeyboard* MyKeyboard::GetInstance()
{
    if (Instance == nullptr) 
    {
        Instance = new MyKeyboard();
    }

    return Instance;
}
void MyKeyboard::Update()
{
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
    {
        Previous[i] = Current[i];
        Current[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
    }
}

bool MyKeyboard::IsKeyUp(sf::Keyboard::Key Key)
{
    return (Current[Key] == false) && (Previous[Key] == false);
}

bool MyKeyboard::IsKeyPressed(sf::Keyboard::Key Key)
{
    return (Current[Key] == true) && (Previous[Key] == false);
}

bool MyKeyboard::IsKeyDown(sf::Keyboard::Key Key)
{
    return (Current[Key] == true) && (Previous[Key] == true);
}

bool MyKeyboard::IsKeyReleased(sf::Keyboard::Key Key)
{
    return (Current[Key] == false) && (Previous[Key] == true);
}


