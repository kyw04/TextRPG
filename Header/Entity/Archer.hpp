#pragma once
#include "Entity.hpp"

class Archer : public Entity
{
public:
    Archer()
    {
        this->name = "궁수";
        this->job = EntityJob::Archer;
        this->attack_type = AttackType::Strength;
        this->stats = Stats
        (
            {
                {StatsName::Health, 75.0f},
                {StatsName::MaxHealth, 75.0f},
                {StatsName::Mana, 50.0f},
                {StatsName::MaxMana, 50.0f},
                
                {StatsName::Strength, 3.5f},
                {StatsName::AttackSpeed, 2.0f},
                {StatsName::Critical, 0.1f}
            }
        );
    }
};