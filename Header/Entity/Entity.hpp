#pragma once
#include <vector>
#include "../Stats.hpp"
#include "../Item/Item.hpp"
#include "../EnumClass.hpp"

class Entity
{
protected:
    bool is_die;

    void virtual Die();

public:
    std::string name;
    EntityJob job;
    AttackType attack_type;
    Stats *stats;

    Entity();
    void TakeDamage(AttackType, float);
    void Fight(Entity*);
    bool IsDie();
};