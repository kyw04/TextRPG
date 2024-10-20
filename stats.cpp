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

void Stats::TakeDamage(float value)
{
    health -= value;

    if (health <= 0)
    {
        health = 0;
        Die();
    }
    else if (health >= max_health)
    {
        health = max_health;
    }
}

void Stats::Die()
{
    is_die = true;
    std::cout << "DIE" << std:: endl;
}