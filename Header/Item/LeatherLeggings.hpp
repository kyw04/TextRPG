#pragma once
#include "Item.hpp"

class LeatherLeggings : public Item
{
public:
    LeatherLeggings() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 1;
        level_requirement = 1;
        job_requirement = EntityJobEnum::All;

        category = (int)ItemCategoryEnum::Equipment | (int)ItemCategoryEnum::Leggings;
        name = "가죽 바지";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::StrengthDefensive, 3.0f},
            }
        );
    }
};