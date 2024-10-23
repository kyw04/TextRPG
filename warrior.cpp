#include <iostream>
#include "./Header/Entity/Warrior.h"


void Warrior::Die()
{
    is_die = true;
    std::cout << "Warrior DIE\n";
}