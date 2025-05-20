#pragma once

#include "Room.h"
#include "SFMLFont.h"
class LevelScoreMenu;
class ScoreMenu : public Room
{
public:
    ScoreMenu();
    ~ScoreMenu();

    void Step() override;
    void Draw() override;

private:
    SFMLFont* Font;
};
