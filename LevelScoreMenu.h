#pragma once

#include "Room.h"
#include "SFMLFont.h"

class LevelScoreMenu : public Room
{
public:
    LevelScoreMenu(int level);
    ~LevelScoreMenu();

    void Step() override;
    void Draw() override;

private:
    int Level;
    SFMLFont* Font;
};