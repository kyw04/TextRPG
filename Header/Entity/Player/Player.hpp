#pragma once
#include "../Entity.hpp"
#include "../../Inventory.hpp"

class Player : public Entity
{
private:

public:
    Player(){ }
    virtual ~Player() { }
    void Die(Entity* _slayer)
    {
        is_die = true;
        std::cout << _slayer->name << "에 의해 " << name << " 죽음\n";
    }
};