#pragma once
#include "Stats.h"



class Entity : public Stats
{
public:
    enum Type
    {
        None,
        Warrior,
        Archer,
        Wizard,
    };

private:
    Type type;

public:
    Entity(Type);
    void ShowEntity();
    void TakeDamage(float);
    void Die();
};