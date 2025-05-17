#include "Wall.h"

Wall::Wall(float x, float y)
	:SolidObject(x, y, "Wall")
{
	SetDepth(0);
}
