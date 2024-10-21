#include <iostream>
#include "./Header/Stats.h"
#include "./Header/Entity.h"

int main()
{
    Entity warrior(Entity::Type::Warrior);
    warrior.ShowEntity();
    warrior.SetExperience(100);
    warrior.ShowEntity();
    warrior.SetExperience(100);
    warrior.ShowEntity();
    
    return 0;
}