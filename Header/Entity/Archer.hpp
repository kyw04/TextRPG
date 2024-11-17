#pragma once
#include "Entity.hpp"

class Archer : public Entity
{
public:
    Archer()
    {
        this->name = "궁수";
        this->job = EntityJob::Archer;
        this->attack_type = AttackType::Strength;
        stats = Stats(75, 75, 50, 50, 3.5f, 0, 2, 0.1);
    }
};