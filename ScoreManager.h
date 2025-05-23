#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>

class ScoreManager {
public:
    static ScoreManager* GetInstance();

    void SaveScore(int level, int steps);
    std::vector<int> GetTopScores(int level);
    std::vector<int> GetScores(int level);
    void LoadAllScores();
    void SaveAllScores();
private:
    ScoreManager() = default;

    std::map<int, std::vector<int>> Scores;
    const std::string FilePath = "levels/scores.txt";

    static ScoreManager* Instance;
};

