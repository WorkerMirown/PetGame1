#include "SFMLObject.h"
#include "Game.h"
#include "TextureManager.h"

SFMLObject::SFMLObject(float x, float y, const std::string& resource,
	int horizontalFrames, int verticalFrames)
	: Sprite(new sf::Sprite()),
	StartPosition(x, y),
	PreviousPosition(x, y),
	IsVisible(true),
	DepthLevel(0.0f),
	Alarms(6, -1),
	SpeedVector(0.0f, 0.0f),
	HorizontalFrames(horizontalFrames),
	VerticalFrames(verticalFrames),
	Image_Index(0),
	Image_Speed(0)
{
	if (resource != "")
	{
		sf::Texture* Texture =
			TextureManager::GetInstanse()->GetTexture(resource);
		Sprite->setTexture(*Texture);
		Sprite->setPosition(x, y);
	}
}

SFMLObject::~SFMLObject()
{
	delete Sprite;
	Sprite = nullptr;
}

void SFMLObject::Step()
{
	//Animateions
	SetImageIndex(ImageIndex() + ImageSpeed());


	//Speed
	Sprite->setPosition(Sprite->getPosition() + SpeedVector);


	//Alarm
	for (int i = 0; i < Alarms.size(); ++i)
	{
		if (Alarms[i] >= 0)
		{
			--Alarms[i];
			if (Alarms[i] == 0)
			{
				OnAlarm(i);
				Alarms[i] = -1;
			}
		}
	}
}

void SFMLObject::Draw()
{
	if (Sprite != nullptr)
	{
		if (IsVisible == true)
		{
			int x = static_cast<int>(ImageIndex()) % HorizontalFrames;
			int y = static_cast<int>(ImageIndex()) % VerticalFrames;
			Sprite->setTextureRect(sf::IntRect(x * SpriteWidth(), y * SpriteHeight(), SpriteWidth(), SpriteHeight()));
			Game::GetInstance()->GetWindow()->draw(*Sprite);
		}

	}
}

sf::Sprite* SFMLObject::GetSprite()
{
	return Sprite;
}

float SFMLObject::X()
{
	return Sprite->getPosition().x;
}

void SFMLObject::SetX(float x)
{
	Sprite->setPosition(x, Sprite->getPosition().y);
}

float SFMLObject::Y()
{
	return Sprite->getPosition().y;
}

void SFMLObject::SetY(float y)
{
	Sprite->setPosition(Sprite->getPosition().x, y);
}

float SFMLObject::XStart()
{
	return StartPosition.x;
}

void SFMLObject::SetXStart(float x)
{
	StartPosition.x = x;
}

float SFMLObject::YStart()
{
	return StartPosition.y;
}

void SFMLObject::SetYStart(float y)
{
	StartPosition.y = y;
}

float SFMLObject::XPrevious()
{
	return PreviousPosition.x;
}

void SFMLObject::SetXPrevious(float x)
{
	PreviousPosition.x = x;
}

float SFMLObject::YPrevious()
{
	return PreviousPosition.x;
}

void SFMLObject::SetYPrevious(float y)
{
	PreviousPosition.y = y;
}

bool SFMLObject::Visible()
{
	return IsVisible;
}

void SFMLObject::SetVisible(bool visible)
{
	IsVisible = visible;
}

float SFMLObject::Depth()
{
	return DepthLevel;
}

void SFMLObject::SetDepth(float depht)
{
	DepthLevel = depht;
}

int SFMLObject::Alarm(int alarm)
{
	return Alarms[alarm];
}

void SFMLObject::SetAlarm(int alarm, int value)
{
	Alarms[alarm] = value;
}

void SFMLObject::OnAlarm(int alarm)
{
	//Do nothing
}

float SFMLObject::XSpeed()
{
	return SpeedVector.x;
}

void SFMLObject::XSpeed(float xspeed)
{
	SpeedVector.x = xspeed;
}

float SFMLObject::YSpeed()
{
	return SpeedVector.y;
}

void SFMLObject::YSpeed(float yspeed)
{
	SpeedVector.y = yspeed;
}

float SFMLObject::Speed()
{
	return hypot(SpeedVector.x, SpeedVector.y);
}
void SFMLObject::SetSpeed(float NewSpeed)
{
	float OldSpeed = Speed();
	if (OldSpeed != 0.0f)
	{
		float factor = NewSpeed / OldSpeed;
		SpeedVector *= factor;
	}
	else
	{
		SpeedVector.x = NewSpeed;
	}
}


void SFMLObject::SetDirection(Direction direction)
{
	switch (direction)
	{
	case Left:
	{
		SpeedVector = sf::Vector2f(-Speed(), 0); break;
	}
	case Right:
		SpeedVector = sf::Vector2f(Speed(), 0); break;
	case Up:
		SpeedVector = sf::Vector2f(0, -Speed()); break;
	case Down:
		SpeedVector = sf::Vector2f(0, Speed()); break;
	default:
		break;
	}
}

float SFMLObject::ImageIndex()
{
	return Image_Index;
}

void SFMLObject::SetImageIndex(float value)
{
	value = fmodf(value, (HorizontalFrames * VerticalFrames));
	if (value < 0)
	{
		value += HorizontalFrames * VerticalFrames;
	}
	Image_Index = value;

}

float SFMLObject::ImageSpeed()
{
	return Image_Speed;
}

void SFMLObject::SetImageSpeed(float value)
{
	Image_Speed = value;
}

int SFMLObject::SpriteWidth()
{
	return Sprite->getTexture()->getSize().x / HorizontalFrames;
}

int SFMLObject::SpriteHeight()
{
	return Sprite->getTexture()->getSize().y / VerticalFrames;

}

bool SFMLObject::IsPointWithinSpriteBounds(float x, float y)
{
	if ((x >= Sprite->getPosition().x) &&
		(x < Sprite->getPosition().x + SpriteWidth()) &&
		(y >= Sprite->getPosition().y) &&
		(y < Sprite->getPosition().y + SpriteHeight())
		)
	{
		return true;
	}
	return false;
}