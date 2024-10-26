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
    std::string name;
    Job job;
    Stats *stats;
    Stats::AttackType attack_type;

    Entity();
    void TakeDamage(Stats::AttackType, float);
    void Fight(Entity*);
    bool IsDie();
};