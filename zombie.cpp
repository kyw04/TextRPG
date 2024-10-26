#include <iostream>
#include "./Header/Entity/Zombie.hpp"

Zombie::Zombie()
{
    this->job = Job::Warrior;
    stats = new Stats(10, 10, 0, 0, 15, 0, 0, 10);
}

void Zombie::Bite()
{

}

void Zombie::Scratch()
{

}