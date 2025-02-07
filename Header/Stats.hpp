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

public:
    Stats();
    Stats(std::vector<std::pair<StatsName, std::variant<float, int, double>>>);
    
    Stats* operator=(const Stats*);
    Stats operator+(const Stats);
    Stats operator-(const Stats);
    Stats* operator+=(const Stats*);
    Stats* operator-=(const Stats*);
    template<typename T>
    void Variance(StatsName, T&, const T&);

    template<typename T>
    void SetStats(StatsName, T);
    template<typename T>
    T GetStats(StatsName);
    std::string GetAllStatsToString();
    void ShowHealth();
    void SetHealth(float);
    void AddHealth(float);
    void SetMana(float);
    void AddMana(float);
    float DefencePercent(AttackType);
    void SetExperience(float);
    void AddExperience(float);
    bool IsEmpty();
};
