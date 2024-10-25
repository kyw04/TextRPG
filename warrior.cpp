#include <iostream>
#include "./Header/Entity/Warrior.h"

Warrior::Warrior()
{
    stats = new Stats(10);
}

void Warrior::Die()
{
    is_die = true;
    std::cout << "Warrior DIE\n";
}