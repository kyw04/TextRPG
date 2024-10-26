#include <iostream>
#include "./Header/Entity/Warrior.hpp"

Warrior::Warrior()
{
    this->job = Job::Warrior;
    stats = new Stats(10);
}

void Warrior::Die()
{
    is_die = true;
    std::cout << "Warrior DIE\n";
}