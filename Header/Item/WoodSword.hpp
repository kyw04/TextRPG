#ifndef _WOOD_SWORD_
#define _WOOD_SWORD_
#include "Item.hpp"

class WoodSword : public Item
{
public:
    WoodSword() : Item(1)
    {
        state = ItemState::Unequipped;
        count = 1;
        level_requirement = 1;
        job_requirement = EntityJob::Warrior;

        category = (int)ItemCategoryEnum::Equipment | (int)ItemCategoryEnum::Weapon;
        name = "나무 검";
        rank = ItemRank::Normal;
        stats = new Stats
        (
            {
                {StatsName::Strength, 10.0f},
                {StatsName::AttackSpeed, 2.0f}
            }
        );
    }
};

#endif