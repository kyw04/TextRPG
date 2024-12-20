#pragma once
#include "Entity.hpp"

class Warrior : public Entity
{
public:
    Warrior()
    {
        this->name = "전사";
        this->job = EntityJob::Warrior;
        this->attack_type = AttackType::Strength;
        stats = Stats
        (
            {
                {StatsName::Health, 100.0f},
                {StatsName::MaxHealth, 100.0f},
                {StatsName::Mana, 50.0f},
                {StatsName::MaxMana, 50.0f},
                
                {StatsName::Strength, 5.0f},
                {StatsName::AttackSpeed, 3.0f}
            }
        );
    }
};