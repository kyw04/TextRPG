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
    Item(const int _max_count = 255) : max_count(_max_count), count(0) {}

    ItemCategory category;
    std::string name;
    const int max_count;
    int count;

    int level_requirement;
    EntityJob job_requirement;

    ItemRank rank;
    Stats* stats;
};