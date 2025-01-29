#pragma once
#include "Player.hpp"

class Archer : public Player
{
public:
    Archer()
    {
        name = "궁수";
        job = EntityJobEnum::Archer;
        attack_type = AttackType::Strength;
        start_stats = Stats
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
        StatsUpdate();
    }
};