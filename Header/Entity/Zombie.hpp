#pragma once
#include "Entity.h"

class Zombie : public Entity
{
private:

public:
    Zombie();

    void Bite();
    void Scratch();
};