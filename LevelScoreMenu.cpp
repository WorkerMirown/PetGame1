#include "LevelScoreMenu.h"
#include "ScoreMenu.h"
#include "Game.h"
#include "MyKeyboard.h"
#include "ScoreManager.h"

LevelScoreMenu::LevelScoreMenu(int level)
    : Level(level), Font(new SFMLFont("font"))
{
}

LevelScoreMenu::~LevelScoreMenu()
{
    delete Font;
}

void LevelScoreMenu::Step()
{
    if (MyKeyboard::GetInstance()->IsKeyDown(sf::Keyboard::Escape))
    {
        Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new ScoreMenu());
    }
}

void LevelScoreMenu::Draw()
{
    Font->Print(380, 40, "Top 10 for Level " + std::to_string(Level), sf::Color::Yellow, 1.2f, 1.2f);

    const auto& scores = ScoreManager::GetInstance()->GetTopScores(Level);

    int y = 120;
    int rank = 1;
    for (int score : scores)
    {
        Font->Print(420, y, std::to_string(rank) + ") " + std::to_string(score) + " steps", sf::Color::White, 1, 1);
        y += 30;
        if (++rank > 10) break;
    }

    Font->Print(300, 470, "ESC - Back to level selection", sf::Color(150, 150, 150), 0.9f, 0.9f);
}
