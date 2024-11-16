#pragma once
#include "EnumClass.hpp"

class Stats
{
private:
    float health;
    float max_health;
    float mana;
    float max_mana;

    float strength;
    float intelligence;
    float attack_speed;
    double critical;

    float strength_defensive;
    float intelligence_defensive;

    int level;
    float experience;
    float next_experience;

    int LevelUP();

public:
    Stats(float = 100, float = 100, float = 100, float = 100, float = 0, float = 0, float = 0, short = 0, float = 0, float = 0, int = 1, float = 0, float = 100); // helath, max_health, mana, max_mana, strength, intglligence, attack_speed, critical, strength_defensive, intelligence_defensive, level, experience, next_experience
    void ShowStats();
    float SetHealth(float);
    float AddHealth(float);
    float GetHealth();
    float SetMana(float);
    float AddMana(float);
    float SetDamage(AttackType, float);
    float SetExperience(float);
    float GetDamage(AttackType);
    float GetAttackSpeed();
};
