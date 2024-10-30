#ifndef _WOOD_SWORD_
#define _WOOD_SWORD_
#include "Item.hpp"

class WoodSword : public Item
{
public:
    WoodSword() 
    {
        state = ItemState::Unequipped;
        level_requirement = 1;
        job_requirement = EntityJob::Warrior;

        category = ItemCategory::Weapon;
        name = "나무 검";
        rank = ItemRank::Normal;
        stats = new Stats(0, 0, 0, 0, 10, 0, 3);
    }
       
};

#endif