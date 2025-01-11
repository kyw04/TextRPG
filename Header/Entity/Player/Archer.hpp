#pragma once
#include "Player.hpp"

class Archer : public Player
{
public:
    Archer()
    {
        name = "궁수";
        job = EntityJob::Archer;
        attack_type = AttackType::Strength;
        start_stats = Stats
        (
            {
                {StatsName::Level, 1},
                {StatsName::Experience, 0.0f},
                {StatsName::NextExperience, 100.0f},
             
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