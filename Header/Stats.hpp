#pragma once
#include "EnumClass.hpp"
#include <vector>
#include <map>
#include <variant>

class Stats
{
private:
    std::map<StatsName, std::variant<float, int, double>> values;

    void LevelUP();

public:
    Stats();
    Stats(std::vector<std::pair<StatsName, std::variant<float, int, double>>>);
    
    template<typename T>
    T& GetStats(StatsName);
    void ShowStats();
    void SetHealth(float);
    void AddHealth(float);
    void SetMana(float);
    void AddMana(float);
    float GetDamage(AttackType, float);
    void SetExperience(float);
};
