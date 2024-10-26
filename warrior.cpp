#include <iostream>
#include "./Header/Entity/Warrior.hpp"

Warrior::Warrior()
{
    this->name = "전사";
    this->job = Job::Warrior;
    this->attack_type = Stats::AttackType::Strength;
    stats = new Stats(100, 100, 50, 50, 3);
}