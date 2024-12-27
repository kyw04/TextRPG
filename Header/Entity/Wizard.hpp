#pragma once
#include "Entity.hpp"

class Wizard : public Entity
{
public:
    Wizard()
    {
        name = "마법사";
        job = EntityJob::Wizard;
        attack_type = AttackType::Intelligence;
        start_stats = Stats
        (
            {
                {StatsName::Health, 50.0f},
                {StatsName::MaxHealth, 50.0f},
                {StatsName::Mana, 100.0f},
                {StatsName::MaxMana, 100.0f},
                
                {StatsName::Intelligence, 7.5f},
                {StatsName::AttackSpeed, 1.0f}
            }
        );
        StatsUpdate();
    }
};