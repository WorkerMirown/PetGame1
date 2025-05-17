#pragma once
#include <SFML/System.hpp> 
#include <string>
#include <SFML/Graphics.hpp>

class Room;

class Game
{
public:
	~Game();
	void ProcessEvents();
	void Draw();
	void Step();
	void Run();
	static Game* GetInstance();

	sf::RenderWindow* GetWindow();

	void ChangeRoom(Room* NewRoom);

	Room* GetCurrentRoom();
	
	float GetFPS();
	void SetFPS(float fps);

	void SetWindowResolution(int width, int height);
	sf::Vector2u GetWindowResolution();

	std::string GetTitleBarText();
	void SetTitleBarText(const std::string & text);

	void QuitGame();

private:
	Game();
	void PossiblyChangeRoom();

	float FramesPerSecond;
	int WindowWidth;
	int WindowHeight;
	std::string TitleBarText;
	sf::RenderWindow * Window;
	sf::Time TimePerFrame;
	Room* CurrentRoom;
	Room* NextRoom;

	static Game* Instance;
};

