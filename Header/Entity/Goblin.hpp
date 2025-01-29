#pragma once
#include "Entity.hpp"
#include "../Item/WoodBow.hpp"
#include "../Item/WoodStaff.hpp"
#include "../Item/WoodSword.hpp"
#include "../Item/LeatherHelmet.hpp"
#include "../Item/LeatherArmor.hpp"
#include "../Item/LeatherLeggings.hpp"
#include "../Item/LeatherShoes.hpp"

class Goblin : public Entity
{
public:
    Goblin()
    {
        name = "고블린";
        job = EntityJobEnum::Archer;
        attack_type = AttackType::Strength;
        start_stats = Stats
        (
            {
                {StatsName::Health, 5.0f},
                {StatsName::MaxHealth, 5.0f},
                
                {StatsName::Strength, 3.0f},
                {StatsName::AttackSpeed, 5.0f},
                {StatsName::Critical, 0.05f}
            }
        );
        StatsUpdate();

        drop_experience = 10.0f;
        drop_items = std::vector<RandomItem<Item*>>
        (
            {
                RandomItem<Item*>(new WoodBow(), 0.01, true),
                RandomItem<Item*>(new WoodSword(), 0.01, true),
                RandomItem<Item*>(new WoodStaff(), 0.01, true),
                RandomItem<Item*>(new LeatherHelmet(), 0.01, true),
                RandomItem<Item*>(new LeatherArmor(), 0.01, true),
                RandomItem<Item*>(new LeatherLeggings(), 0.01, true),
                RandomItem<Item*>(new LeatherShoes(), 0.01, true),
            }
        );
    }
};