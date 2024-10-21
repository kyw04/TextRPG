#include <iostream>
#include <random>
#include "./Header/Stats.h"


Stats::Stats(bool _is_die, float _health, float _max_health, float _mana, float _max_mana, float _strength, float _intelligence, float _attack_speed, short _critical, float _strength_defensive, float _intelligence_defensive, int _level, float _experience, float _next_experience) :
    is_die(_is_die),
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

float Stats::SetHealth(float value)
{
    return health = value > max_health ? max_health : value;
}

float Stats::SetMana(float value)
{
    return mana = value > max_mana ? max_mana : value;
}

float Stats::SetDamage(AttackType attack_type, float suffered_damage)
{
    float defense_percentage;
    switch (attack_type)
    {
    case AttackType::Strength:
        defense_percentage = strength_defensive / (strength_defensive + 1);
        break;
    case AttackType::Intelligence:
        defense_percentage = intelligence_defensive / (intelligence_defensive + 1);
        break;
    default:
        return 0.0f;
        break;
    }

    return suffered_damage * (defense_percentage - 1);
}

float Stats::SetExperience(float value)
{
    experience = value;
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