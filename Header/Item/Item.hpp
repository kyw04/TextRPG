#pragma once
#include <string>
#include "../Stats.hpp"
#include "../EnumClass.hpp"

class Item
{
protected:
    ItemState state;

public:
    ItemCategory category;
    std::string name;

    int level_requirement;
    EntityJob job_requirement;

    ItemRank rank;
    Stats* stats;
};