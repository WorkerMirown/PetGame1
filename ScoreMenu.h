#pragma once
#include "Room.h"
#include "SFMLFont.h"


class ScoreMenu : public Room
{
public:
    ScoreMenu();
    ~ScoreMenu();

    void Draw() override;
  

private:
    SFMLFont* Font;
};
