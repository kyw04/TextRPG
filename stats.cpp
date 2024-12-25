#include <iostream>
#include <map>
#include "./Header/Stats.hpp"

Stats::Stats()
{

}

Stats::Stats(std::vector<std::pair<StatsName, std::variant<float, int, double>>> _array)
{
    for (auto& a : _array)
    {
        stats.insert(a);
    }
}

Stats& Stats::operator+=(const Stats& _stats)
{
    for (auto& s : _stats.stats)
    {
        if (stats.find(s.first) != stats.end())
        {
            if (std::get_if<int>(&s.second) != nullptr)
                std::get<int>(stats.find(s.first)->second) += std::get<int>(s.second);
            if (std::get_if<float>(&s.second) != nullptr)
                std::get<float>(stats.find(s.first)->second) += std::get<float>(s.second);
            if (std::get_if<double>(&s.second) != nullptr)
                std::get<double>(stats.find(s.first)->second) += std::get<double>(s.second);
        }
        else
        {
            stats.insert(s);
        }
    }

    return *this;
}

std::string Stats::GetAllStatsToString()
{
    std::string result;
    result.clear();

    for (auto& s : stats)
    {
        result.append(EnumToString<StatsName>(s.first)).append(": ");

        if (std::get_if<int>(&s.second) != nullptr)
        {
            result.append(std::to_string(std::get<int>(s.second))).append("\n");
            continue;
        }
        if (std::get_if<float>(&s.second) != nullptr)
            result.append(std::to_string(std::get<float>(s.second)));
        if (std::get_if<double>(&s.second) != nullptr)
            result.append(std::to_string(std::get<double>(s.second)));
        result.erase(result.end() - 4, result.end());
        result.append("\n");
    }

    return result;
}

template<typename T>
T Stats::GetStats(StatsName _name)
{
    if (stats.find(_name) == stats.end())
    {
        return 0;
    }
    return std::get<T>(stats.find(_name)->second);
}

template<typename T>
void Stats::SetStats(StatsName _name, T _value)
{
    if (stats.find(_name) != stats.end())
    {
        stats.find(_name)->second = _value;
    }
}

void Stats::SetHealth(float _value)
{
    float max_health = GetStats<float>(StatsName::MaxHealth);
    SetStats<float>(StatsName::Health, _value > max_health ? max_health : _value);
}

void Stats::AddHealth(float _value)
{
    SetHealth(GetStats<float>(StatsName::Health) + _value);
}

void Stats::SetMana(float _value)
{
    float max_mana = GetStats<float>(StatsName::MaxMana);
    SetStats<float>(StatsName::Mana, _value > max_mana ? max_mana : _value);
}

void Stats::AddMana(float _value)
{
    SetMana(GetStats<float>(StatsName::Mana) + _value);
}

void Stats::SetExperience(float _value)
{
    float experience = GetStats<float>(StatsName::Experience);
    float next_experience = GetStats<float>(StatsName::NextExperience);

    SetStats<float>(StatsName::Experience, _value);
    if (experience >= next_experience)
    {
        LevelUP();
    }
}

void Stats::LevelUP()
{
    int level = GetStats<int>(StatsName::Level);
    float experience = GetStats<float>(StatsName::Experience);
    float next_experience = GetStats<float>(StatsName::NextExperience);

    SetStats<int>(StatsName::Level, ++level);
    SetStats<float>(StatsName::Experience, experience - next_experience);
    SetStats<float>(StatsName::NextExperience, float(level * (level + 1)) * 25.0f - 50.0f);
}

float Stats::GetDamage(AttackType _attack_type, float _damage)
{
    float defense_percentage;
    switch (_attack_type)
    {
    case AttackType::Strength:
    {
        float strength_defensive = GetStats<float>(StatsName::StrengthDefensive);

        defense_percentage = strength_defensive / (strength_defensive + 1);
        break;
    }
    case AttackType::Intelligence:
    {
        float intelligence_defensive = GetStats<float>(StatsName::IntelligenceDefensive);
        
        defense_percentage = intelligence_defensive / (intelligence_defensive + 1);
        break;
    }
    default:
        defense_percentage = 0.0f;
        break;
    }

    return _damage * (defense_percentage - 1);
}