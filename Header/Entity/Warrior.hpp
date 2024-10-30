#pragma once
#include "Entity.hpp"

class Warrior : public Entity
{
public:
    Warrior()
    {
        this->name = "전사";
        this->job = EntityJob::Warrior;
        this->attack_type = AttackType::Strength;
        stats = new Stats(100, 100, 50, 50, 3);
    }
};