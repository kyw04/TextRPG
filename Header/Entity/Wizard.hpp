#pragma once
#include "Entity.hpp"

class Wizard : public Entity
{
public:
    Wizard()
    {
        this->name = "마법사";
        this->job = EntityJob::Wizard;
        this->attack_type = AttackType::Intelligence;
        stats = Stats
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
    }
};