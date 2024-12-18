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
        stats = Stats // 75, 75, 50, 50, 3.5f, 0, 2, 0.1
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