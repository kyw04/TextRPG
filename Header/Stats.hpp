#pragma once
#include "EnumClass.hpp"
#include <string>
#include <vector>
#include <map>
#include <variant>

class Stats
{
private:
    std::map<StatsName, std::variant<float, int, double>> stats;

    void LevelUP();
    template<typename T>
    void SetStats(StatsName, T);

public:
    Stats();
    Stats(std::vector<std::pair<StatsName, std::variant<float, int, double>>>);
    
    template<typename T>
    T GetStats(StatsName);
    std::string GetAllStatsToString();
    void SetHealth(float);
    void AddHealth(float);
    void SetMana(float);
    void AddMana(float);
    float GetDamage(AttackType, float);
    void SetExperience(float);
};
