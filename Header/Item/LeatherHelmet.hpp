#pragma once
#include "Item.hpp"

class LeatherHelmet : public Item
{
public:
    LeatherHelmet() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 1;
        level_requirement = 1;
        job_requirement = EntityJobEnum::All;

        category = (int)ItemCategoryEnum::Equipment | (int)ItemCategoryEnum::Helmet;
        name = "가죽 헬멧";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::StrengthDefensive, 2.0f},
            }
        );
    }
};