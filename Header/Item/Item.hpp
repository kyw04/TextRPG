#pragma once
#include <string>
#include "../Stats.hpp"

class Item
{
public:
    enum Category
    {
        Accessory, // 부속품
        Consumable, // 소모품
        Equipment, // 장비
        Weapon, // 무기
    };

    enum State
    {
        Unequipped,
        Equipped,
    };

    enum Rank
    {
        None,
        Normal,
        Rare,
        Unique,
        Legendary
    };

private:

public:
    Category category;
    std::string name;

    int level_requirement;
    

    State state;
    Rank rank;
    Stats* stats;
};