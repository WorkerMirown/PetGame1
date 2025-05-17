#include "SFMLButton.h"
#include "Mouse.h"

SFMLButton::SFMLButton(	float x,
						float y,
						const std::string& spriteResource,
						void (*callback)()
)
	   :SFMLObject(x, y, spriteResource, 2, 1),
		Callback(callback)

{
	SetImageSpeed(60.0f);
}



void SFMLButton::Step()
{
	sf::Vector2i mouse = Mouse::GetInstance()->GetMousePosition();
	SetImageIndex(0);
	if (IsPointWithinSpriteBounds(mouse.x, mouse.y) == true)
	{
		SetImageIndex(1);
		if (Mouse::GetInstance()->IsBottonPressed(sf::Mouse::Left) == true)
		{
			Callback();
		}
	}
}


