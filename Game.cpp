#include <iostream>
#include "Game.h"
#include "MyKeyboard.h" 
#include "Mouse.h"
#include "GameInitRoom.h"

Game * Game::Instance = nullptr;


Game::Game()
// Create the main window
   :FramesPerSecond(60.f),
    WindowHeight(1280),
    WindowWidth(768),
    TitleBarText("SokobanByDenisova"),
    Window(new sf::RenderWindow(sf::VideoMode((WindowHeight), (WindowWidth) ), TitleBarText)),
    TimePerFrame(sf::seconds(2.0f / FramesPerSecond)),
    CurrentRoom(new GameInitRoom()),
    NextRoom(nullptr)
{
	//Nothing here
}
Game::~Game()
{
    delete Window;
}
void Game::PossiblyChangeRoom()
{
    if (NextRoom != nullptr) {
        delete CurrentRoom;
        CurrentRoom = NextRoom;
        NextRoom = nullptr;
    }
}

void Game::ProcessEvents()
{
    sf::Event event;
    while(Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Window->close();
        }
    }
    
}
void Game::Draw()
{
    // Clear screen
    Window->clear();
    // Draw the sprite
    CurrentRoom->Draw();
    // Update the window
    Window->display();
}

void Game::Step()
{
    CurrentRoom->Step();
}

void Game::Run()
{
    // Start the game loop
    sf::Clock Clock;
    sf::Time TimeSinceLastUpdate = sf::Time::Zero;

    while (Window->isOpen())
    {
        TimeSinceLastUpdate += Clock.restart();
        ProcessEvents();
        while (TimeSinceLastUpdate > TimePerFrame)
        {
            MyKeyboard::GetInstance()->Update();
            Mouse::GetInstance()->Update();
            TimeSinceLastUpdate -= TimePerFrame;
            Step();
            ProcessEvents();
        }
        Draw();
        PossiblyChangeRoom();
    }
}

sf::RenderWindow* Game::GetWindow()
{
    return Window;
}

Room* Game::GetCurrentRoom()
{
    return CurrentRoom;
}

void Game::ChangeRoom(Room* NewRoom)
{
    if (NextRoom == nullptr)
    {
        NextRoom = NewRoom;
    }
    else
    {
        delete NewRoom;
    }
}

Game* Game::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new Game();
    }

    return Instance;
}

float Game::GetFPS()
{
    return FramesPerSecond;
}

void Game::SetFPS(float fps)
{
    FramesPerSecond = fps;
    TimePerFrame = sf::seconds(1.0f / FramesPerSecond);
}

void Game::SetWindowResolution(int width, int height)
{
    delete Window;
    WindowWidth = width;
    WindowHeight = height;
    Window = new sf::RenderWindow(sf::VideoMode({ static_cast<unsigned int>(WindowHeight), static_cast<unsigned int>(WindowWidth) }), TitleBarText);
}

sf::Vector2u Game::GetWindowResolution()
{
    return Window ->getSize();
}

std::string Game::GetTitleBarText()
{
    return TitleBarText;
}

void Game::SetTitleBarText(const std::string& text)
{
    TitleBarText = text;
    Window->setTitle(TitleBarText);
}

void Game::QuitGame()
{
    exit(0);
}

