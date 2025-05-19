#pragma once

#include "SFMLObject.h"

class SFMLFont : public SFMLObject
{
public: SFMLFont(const std::string& resource = "font");


	  void Print(
		 int x,
		 int y,
		 const std::string& text,
		 sf::Color tint = sf::Color::White,
		 float xScale = 1.0F,
		 float yScale = 1.0f
	  );

};

