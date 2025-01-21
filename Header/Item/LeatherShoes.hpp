#pragma once
#include "Item.hpp"

class LeatherShoes : public Item
{
public:
    LeatherShoes() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 1;
        level_requirement = 1;
        job_requirement = EntityJobEnum::All;

        category = (int)ItemCategoryEnum::Equipment | (int)ItemCategoryEnum::Shoes;
        name = "가죽 신발";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::StrengthDefensive, 1.0f},
            }
        );
    }
};