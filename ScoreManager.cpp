#include "ScoreManager.h"
#include <sstream>
#include <filesystem>

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
    return Scores[level];
}

void ScoreManager::LoadAllScores() {
    Scores.clear();
    std::ifstream file(FilePath);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int level, steps;
        char sep;
        if (iss >> level >> sep && sep == ':') {
            while (iss >> steps) {
                Scores[level].push_back(steps);
            }
            std::sort(Scores[level].begin(), Scores[level].end());
            if (Scores[level].size() > 10)
                Scores[level].resize(10);
        }
    }

    file.close();
}

void ScoreManager::SaveAllScores() {
    std::ofstream file(FilePath, std::ios::trunc);
    if (!file.is_open()) return;

    for (const auto& [level, scores] : Scores) {
        file << level << ":";
        for (int s : scores)
            file << " " << s;
        file << "\n";
    }

    file.close();
}
