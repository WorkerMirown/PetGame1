#include <iostream>
#include "Game.h"


int main()
{
    std::cout << "GameStart" << std::endl;
    Game::GetInstance()->Run();
    return 0;
}
