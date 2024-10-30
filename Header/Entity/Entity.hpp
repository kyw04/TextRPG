#pragma once
#include <vector>
#include "../Stats.hpp"
#include "../Item/Item.hpp"
#include "../EnumClass.hpp"

class Entity
{
protected:
    std::vector<std::pair<Item, short>> drop_item; // pair<item, percent>
    bool is_die;

    void virtual Die();

public:
    std::string name;
    EntityJob job;
    Stats *stats;
    AttackType attack_type;

    Entity();
    void TakeDamage(AttackType, float);
    void Fight(Entity*);
    bool IsDie();
};