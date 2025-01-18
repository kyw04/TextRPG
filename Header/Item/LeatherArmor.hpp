#pragma once
#include "Item.hpp"

class LeatherArmor : public Item
{
public:
    LeatherArmor() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 1;
        level_requirement = 1;
        job_requirement = EntityJobEnum::All;

        category = (int)ItemCategoryEnum::Equipment | (int)ItemCategoryEnum::Armor;
        name = "가죽 갑옷";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::StrengthDefensive, 7.0f},
            }
        );
    }
};