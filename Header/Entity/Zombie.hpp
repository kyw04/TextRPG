#pragma once
#include "Entity.hpp"

class Zombie : public Entity
{
public:
    Zombie()
    {
        name = "좀비";
        job = EntityJob::Warrior;
        attack_type = AttackType::Strength;
        start_stats = Stats
        (
            {
                {StatsName::Level, 1},
                {StatsName::Experience, 0},
                {StatsName::NextExperience, 100},

                {StatsName::Health, 30.0f},
                {StatsName::MaxHealth, 10.0f},
                
                {StatsName::Strength, 15.0f},
                {StatsName::AttackSpeed, 3.0f},
                {StatsName::Critical, 0.1f}
            }
        );
        StatsUpdate();
    }
};