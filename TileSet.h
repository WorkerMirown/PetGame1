#pragma once

#include "SFMLObject.h"

class Tileset : public SFMLObject
{
public:
	Tileset(float x, float y);

	virtual void Step() override;
};