#include <iostream>
#include "./Header/Entity/Zombie.hpp"

Zombie::Zombie()
{
    this->name = "좀비";
    this->job = Job::Warrior;
    this->attack_type = Stats::AttackType::Strength;
    stats = new Stats(10, 10, 0, 0, 15, 0, 0, 10);
}