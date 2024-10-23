#include <iostream>
#include "./Header/Stats.h"
#include "./Header/Entity/Entity.h"
#include "./Header/Entity/Warrior.h"

int main()
{
    Warrior warrior;
    warrior.ShowStats();
    warrior.TakeDamage(10);
    warrior.ShowStats();
    warrior.TakeDamage(100);

    return 0;
}