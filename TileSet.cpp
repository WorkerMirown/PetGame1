#include "TileSet.h"
#include <iostream>

Tileset::Tileset(float x, float y)
	:SFMLObject(x, y, "Tileset",6,4)
{
	SetImageSpeed(1.0f);
}

void Tileset::Step()
{
	SFMLObject::Step();
	std::cout << ImageIndex();

}
