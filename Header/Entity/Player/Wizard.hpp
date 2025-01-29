#pragma once
#include "Player.hpp"

class Wizard : public Player
{
public:
    Wizard()
    {
        name = "마법사";
        job = EntityJobEnum::Wizard;
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