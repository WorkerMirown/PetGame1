#include <fstream>
#include <iostream>
#include <string>
#include "Box.h"
#include "Hero.h"
#include "Goal.h"
#include "Wall.h"
#include "GameLevelRoom.h"

GameLevelRoom::GameLevelRoom()
    :Room()
{
    std::ifstream file("level.txt");

    while (file.eof() == false)
    {
        objects.clear();
        std::string line;
        int y = 0;
        while (std::getline(file, line)) {
            for (int x = 0; x < line.length(); ++x) {
                char symbol = line[x];
                std::string texturePath;

                switch (symbol) {
                case '#': texturePath = "assets/wall.png"; break;
                case ' ': texturePath = "assets/floor.png"; break;
                case 'B': texturePath = "assets/box.png"; break;
                case 'G': texturePath = "assets/goal.png"; break;
                case 'P': texturePath = "assets/player.png"; break;
                default: continue; // пропускаем неизвестные символы
                }
            SFMLObject obj(texturePath);
            obj.setPosition(static_cast<float>(x * TILE_SIZE), static_cast<float>(y * TILE_SIZE));
            objects.push_back(obj);
            }
            y++;
        }
    }
    file.close();

}