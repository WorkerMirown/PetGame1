#include <iostream>
#include "Game.h"


int main()
{
    //Game * Instance = Game::GetInstance();
    //Instance->SetFPS(60);
    //Instance->SetWindowResolution(200, 200);
    //Instance->SetTitleBarText("Hello Valshtein");

    Game::GetInstance()->Run();
    return 0;
}
