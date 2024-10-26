#pragma once
#include <vector>
#include "../Stats.hpp"
#include "../Item/Item.hpp"

class Entity
{
public: 
    enum Job
    {
        None,
        Warrior,
        Archer,
        Wizard,
    };

protected:
    std::vector<std::pair<Item, short>> drop_item; // pair<item, percent>
    bool is_die;

    void virtual Die();

public:
    Job job;
    Stats *stats;

    Entity();
    void TakeDamage(float);
    bool IsDie();
};