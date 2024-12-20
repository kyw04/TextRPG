#ifndef _WOOD_BOW_
#define _WOOD_BOW_
#include "Item.hpp"

class WoodBow : public Item
{
public:
    WoodBow() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 0;
        level_requirement = 1;
        job_requirement = EntityJob::Archer;

        category = ItemCategory::Weapon;
        name = "나무 활";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::Strength, 7.0f},
                {StatsName::AttackSpeed, 3.0f},
                {StatsName::Critical, 3.0f}
            }
        );
    }
};

#endif