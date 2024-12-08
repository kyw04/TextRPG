#include <iostream>
#include "./Header/Stats.hpp"


Stats::Stats(float _health, float _max_health, float _mana, float _max_mana, float _strength, float _intelligence, float _attack_speed, double _critical, float _strength_defensive, float _intelligence_defensive, int _level, float _experience, float _next_experience) :
    health(_health),
    max_health(_max_health),
    mana(_mana),
    max_mana(_max_mana),
    strength(_strength),
    intelligence(_intelligence),
    attack_speed(_attack_speed),
    critical(_critical),
    strength_defensive(_strength_defensive),
    intelligence_defensive(_intelligence_defensive),
    level(_level),
    experience(_experience),
    next_experience(_next_experience) {}


void Stats::ShowStats()
{
    std::cout << "체력\t\t[" << health << "/" << max_health << "]\n";
    std::cout << "마나\t\t[" << mana << "/" << max_mana << "]\n";
    std::cout << "물리 공격력\t[" << strength << "]\n";
    std::cout << "마법 공격력\t[" << intelligence << "]\n";
    std::cout << "공격 속도\t[" << attack_speed << "]\n";
    std::cout << "크리티컬 확률\t[" << critical << "]\n";
    std::cout << "물리 방어력\t[" << strength_defensive << "]\n";
    std::cout << "마법 방어력\t[" << intelligence_defensive << "]\n";
    std::cout << "레벨\t\t[" << level << "]\n";
    std::cout << "경험치\t\t[" << experience << "/" << next_experience << "]\n";
}

float Stats::SetHealth(float _value)
{
    return health = _value > max_health ? max_health : _value;
}

float Stats::AddHealth(float _value)
{
    return SetHealth(health + _value);
}

float Stats::SetMana(float _value)
{
    return mana = _value > max_mana ? max_mana : _value;
}

float Stats::AddMana(float _value)
{
    return SetMana(mana + _value);
}

float Stats::SetDamage(AttackType _attack_type, float _damage)
{
    float defense_percentage;
    switch (_attack_type)
    {
    case AttackType::Strength:
        defense_percentage = strength_defensive / (strength_defensive + 1);
        break;
    case AttackType::Intelligence:
        defense_percentage = intelligence_defensive / (intelligence_defensive + 1);
        break;
    default:
        defense_percentage = 0.0f;
        break;
    }

    return _damage * (defense_percentage - 1);
}

float Stats::SetExperience(float _value)
{
    experience = _value;
    if (experience >= next_experience)
    {
        experience -= next_experience;
        LevelUP();
    }
    return experience;
}

int Stats::LevelUP()
{   
    level++;
    experience = 0;
    next_experience = float(level * (level + 1)) * 25.0f - 50.0f;
    return level;
}

float Stats::GetDamage(AttackType _type)
{
    return _type == AttackType::Strength ? strength : intelligence;
}

template<typename T>
T Stats::GetStats(const StatsName _name)
{
    switch (_name)
    {
    case StatsName::Health:
        return health;
    case StatsName::AttackSpeed:
        return attack_speed;
    default:
        break;
    }

    return 0.0f;
}
