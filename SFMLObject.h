#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

class Game;

class SFMLObject
{
	friend class SFMLFont;

public:
	SFMLObject(float x, float y, const std::string& resource= "", 
		int horizontalFrames = 1, int verticalFrames = 1);

	virtual ~SFMLObject();

	virtual void Step();
	virtual void Draw();
	sf::Sprite* GetSprite();

	float X();
	void SetX(float x);
	float Y();
	void SetY(float y);
	
	float XStart();
	void SetXStart(float x);
	float YStart();
	void SetYStart(float y);
	
	
	float XPrevious();
	void SetXPrevious(float x);
	float YPrevious();
	void SetYPrevious(float y);

	bool Visible();
	void SetVisible(bool visible);

	float Depth();
	void SetDepth(float depht);

	int Alarm(int alarm);
	void SetAlarm(int alarm, int value);
	virtual void OnAlarm(int alarm);

	float XSpeed();
	void  XSpeed(float xspeed);
	float YSpeed();
	void  YSpeed(float yspeed);

	float Speed();
	void SetSpeed(float speed);

	enum Direction
	{
		Left,
		Right,
		Up,
		Down
	};
	void SetDirection(Direction direction);
	
	float ImageIndex();
	void SetImageIndex(float value);

	float ImageSpeed();
	void SetImageSpeed(float value);

	int SpriteWidth();
	int SpriteHeight();

	bool IsPointWithinSpriteBounds(float x, float y);

	template <typename T>
	std::vector<T> GetAllGameObjectAtPosition(float x, float y);
	
	template <typename T>
	std::vector<T> GetAllGameObjectOfType();

private:
	sf::Sprite*			Sprite;
	sf::Vector2f		StartPosition;
	sf::Vector2f		PreviousPosition;
	bool				IsVisible;
	float				DepthLevel;
	std::vector<int>	Alarms;
	sf::Vector2f		SpeedVector;
	int					HorizontalFrames;
	int					VerticalFrames;
	float				Image_Index;
	float				Image_Speed;
	
};

template<typename T>
inline std::vector<T> SFMLObject::GetAllGameObjectAtPosition(float x, float y)
{
	return Game::GetInstance()->GetCurrentRoom()->GetAllGameObjectAtPosition<T>(x,y);
}
template<typename T>
inline std::vector<T> SFMLObject::GetAllGameObjectOfType()
{
	return Game::GetInstance()->GetCurrentRoom()->template GetAllGameObjectOfType<T>();
}
