#ifndef _WOOD_STAFF_
#define _WOOD_STAFF_
#include "Item.hpp"

class WoodStaff : public Item
{
public:
    WoodStaff() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 0;
        level_requirement = 1;
        job_requirement = EntityJob::Wizard;

        category = ItemCategory::Weapon;
        name = "나무 지팡이";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::Intelligence, 12.0f},
                {StatsName::AttackSpeed, 1.0f},
            }
        );
    }
};

#endif