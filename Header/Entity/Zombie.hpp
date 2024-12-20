#pragma once
#include "Entity.hpp"

class Zombie : public Entity
{
public:
    Zombie()
    {
        this->name = "좀비";
        this->job = EntityJob::Warrior;
        this->attack_type = AttackType::Strength;
        stats = Stats
        (
            {
                {StatsName::Health, 10.0f},
                {StatsName::MaxHealth, 10.0f},
                
                {StatsName::Strength, 15.0f},
                {StatsName::AttackSpeed, 3.0f},
                {StatsName::Critical, 0.1f}
            }
        );
    }
};