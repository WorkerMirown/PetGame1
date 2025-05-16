#include <fstream>
#include <iostream>
#include <string>
#include "Box.h"
#include "Hero.h"
#include "Goal.h"
#include "Wall.h"
#include "TileSet.h"
#include "GameLevelRoom.h"

GameLevelRoom::GameLevelRoom(const std::string& filename, int levelNumber)
    :Room(),
    LevelNumber(levelNumber)
{
    InstanceCreate(new Tileset(0,0));
    //std::ifstream file(filename);
    //if (file.fail())
    //{
    //    std::exception("Fail to load LevelFile");
    //}
    //if (file.is_open()) {
    //    while (file.eof() == false)
    //    {
    //        const float TILE_SIZE = 64; // размер клетки
    //        std::string line;
    //        float y = 0;
    //        while (std::getline(file, line)) {
    //            for (float x = 0; x < line.length(); ++x) {
    //                char symbol = line[x];
    //                float posX = x * TILE_SIZE;
    //                float posY = y * TILE_SIZE;

    //                switch (symbol) {
    //                case '#': InstanceCreate(new Wall(posX, posY)); break;
    //                case 'B': InstanceCreate(new Box(posX, posY)); break;
    //                case 'G': InstanceCreate(new Goal(posX, posY)); break;
    //                case 'P': InstanceCreate(new Hero(posX, posY)); break;
    //                default: continue;
    //                }
    //            }
    //            y++;
    //        }
    //    }file.close();
    // file.close();
    //}
    //else {
    //    std::cerr << "Не удалось открыть файл." << std::endl; // Обработка ошибки
    //}

}