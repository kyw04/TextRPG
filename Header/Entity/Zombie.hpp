#pragma once
#include "Entity.hpp"

class Zombie : public Entity
{
public:
    Zombie()
    {
        this->name = "좀비";
        this->job = EntityJob::Warrior;
        this->attack_type = AttackType::Strength;
        // stats = Stats(10, 10, 0, 0, 15, 0, 3, 0.1);
    }
};