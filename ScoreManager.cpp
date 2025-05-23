#include "ScoreManager.h"
#include <sstream>
#include <algorithm>

ScoreManager* ScoreManager::Instance = nullptr;

ScoreManager* ScoreManager::GetInstance() {
    if (!Instance)
        Instance = new ScoreManager();
    return Instance;
}

void ScoreManager::SaveScore(int level, int steps) {
    std::vector<int>& topScores = Scores[level];
    topScores.push_back(steps);

    std::sort(topScores.begin(), topScores.end());

    if (topScores.size() > 10)
        topScores.resize(10);

    SaveAllScores();
}

std::vector<int> ScoreManager::GetTopScores(int level) {
    if (Scores.find(level) != Scores.end())
        return Scores[level];
    else
        return {}; // ѕустой вектор, если очков нет
}

void ScoreManager::LoadAllScores() {
    Scores.clear();
    std::ifstream file(FilePath);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int level;
        char sep;
        if (!(iss >> level >> sep) || sep != ':') continue;

        int score;
        while (iss >> score) {
            Scores[level].push_back(score);
        }

        std::sort(Scores[level].begin(), Scores[level].end());
        if (Scores[level].size() > 10)
            Scores[level].resize(10);
    }

    file.close();
}
std::vector<int> ScoreManager::GetScores(int level) {
    if (Scores.count(level))
        return Scores[level];
    return {}; // если нет очков Ч вернуть пустой вектор
}

void ScoreManager::SaveAllScores() {
    std::ofstream file(FilePath, std::ios::trunc);
    if (!file.is_open()) return;

    for (const auto& [level, scores] : Scores) {
        file << level << ":";
        for (int score : scores)
            file << " " << score;
        file << "\n";
    }

    file.close();
}
