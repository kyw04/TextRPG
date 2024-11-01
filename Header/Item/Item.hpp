#pragma once
#include <string>
#include <iostream>
#include "../Stats.hpp"
#include "../EnumClass.hpp"

class Item
{
protected:
    ItemState state;

public:
    bool operator==(const Item&) const;
    friend std::ostream& operator<<(std::ostream&, const Item&);
    Item() : max_count(255) {}

    ItemCategory category;
    std::string name;
    const unsigned short max_count;
    unsigned short count;
    short slot;

    int level_requirement;
    EntityJob job_requirement;

    ItemRank rank;
    Stats* stats;
};