#pragma once
#include "Entity.hpp"

class Zombie : public Entity
{
private:

public:
    Zombie();

    void Bite();
    void Scratch();
};