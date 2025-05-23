#include <fstream>
#include <iostream>
#include <string>
#include "Box.h"
#include "Hero.h"
#include "Goal.h"
#include "Wall.h"
#include "FloarL.h"
#include "FloarB.h"
#include "SFMLButton.h"
#include "MainMenuBackground.h"
#include "GameLevelRoom.h"
#include "Game.h"
#include "MainMenuRoom.h"
#include "FadeOutAndChangeRoom.h"
#include "SFMLFadeIn.h"

inline void ReturnToMainMenu()
{
    Game::GetInstance()->GetCurrentRoom()->InstanceCreate(new FadeOutAndChangeRoom(new MainMenuRoom));
}

GameLevelRoom::GameLevelRoom(const std::string& filename, int levelNumber)
    :Room(),
    LevelNumber(levelNumber)
{
    
    std::ifstream file(filename);
    if (file.fail())
    {
        std::exception("Fail to load LevelFile");
    }
    if (file.is_open()) {
        while (file.eof() == false)
        {
            const float TILE_SIZE = 64.0f; // 
            std::string line;
            float y = 0.0f;

            while (std::getline(file, line)) {
                for (int x = 0; x < line.length(); ++x) {
                    char symbol = line[x];
                    float posX = x * TILE_SIZE;
                    float posY = y * TILE_SIZE;

                    switch (symbol) {
                    case '#': InstanceCreate(new Wall(posX, posY)); break;
                    case 'B': InstanceCreate(new FloarL(posX, posY));
                        InstanceCreate(new Box(posX, posY));break;
                    case 'G': InstanceCreate(new Goal(posX, posY)); break;
                    case 'P':  InstanceCreate(new FloarL(posX, posY));
                    InstanceCreate(new Hero(posX, posY, levelNumber)); break;
                    case '1': InstanceCreate(new FloarL(posX, posY)); break;
                    case '2': InstanceCreate(new FloarB(posX, posY)); break;
                    default: continue;
                    }
                }
                y++;
            }
        }
        InstanceCreate(new SFMLFadeIn());
     file.close();
    }
    else {
        std::cerr << "Ошибка открытия файла»." << std::endl; 
    }

}