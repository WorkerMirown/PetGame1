#include "Box.h"

Box::Box(float x, float y)
	:SolidObject(x, y, "Box")
{
	SetDepth(3);
}

void Box::OnAlarm(int alarm)
{
	SetSpeed(0);
}

