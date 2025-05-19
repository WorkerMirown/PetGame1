#pragma once
#include "SFMLFont.h"
#include "SFMLObject.h"

class SFMLButton : public SFMLObject
{
public:
	SFMLButton(
		float x,
		float y,
		const std::string& spriteResource,
		void(*callback)()
	);


	virtual void Step() override;

private:
	void (*Callback)();

};

