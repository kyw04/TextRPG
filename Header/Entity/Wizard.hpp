#pragma once
#include "Entity.hpp"

class Wizard : public Entity
{
public:
    Wizard()
    {
        this->name = "마법사";
        this->job = EntityJob::Wizard;
        this->attack_type = AttackType::Intelligence;
        stats = new Stats(50, 50, 100, 100, 0, 7.5f, 1, 0);
    }
};