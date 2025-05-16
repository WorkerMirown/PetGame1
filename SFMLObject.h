#pragma once
#include <SFML/Graphics.hpp>
class SFMLObject
{
public:
	SFMLObject(float x, float y, const std::string& resource= "", 
		int horizontalFrames =1, int verticalFrames=1);

	virtual ~SFMLObject();

	virtual void Step();
	virtual void Draw();
//	void setPosition(float x, float y);

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
	float Direction();
	void SetDirection(float direction);

	float ImageIndex();
	void SetImageIndex(float value);

	float ImageSpeed();
	void SetImageSpeed(float value);

	int SpriteWidth();
	int SpriteHeight();

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

