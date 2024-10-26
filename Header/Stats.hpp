#pragma once

class Stats
{
public:
    enum AttackType
    {
        None,
        Strength,
        Intelligence
    };

protected:
    float health;
    float max_health;
    float mana;
    float max_mana;

    float strength;
    float intelligence;
    float attack_speed;
    short critical;

    float strength_defensive;
    float intelligence_defensive;

    int level;
    float experience;
    float next_experience;

    int LevelUP();

public:
    Stats(float = 100, float = 100, float = 100, float = 100, float = 0, float = 0, float = 0, short = 0, float = 0, float = 0, int = 1, float = 0, float = 100);
    void ShowStats();
    float SetHealth(float);
    float AddHealth(float);
    float SetMana(float);
    float AddMana(float);
    float SetDamage(AttackType, float);
    float SetExperience(float);
};
