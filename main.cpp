#include <iostream>
#include "./Header/Stats.hpp"
#include "./Header/Entity/Entity.hpp"
#include "./Header/Entity/Warrior.hpp"
#include "./Header/Entity/Zombie.hpp"

int main()
{
    int input;
    Warrior *warrior = new Warrior();
    while (!warrior->IsDie())
    {

        Zombie* zombie = new Zombie();
        while (!zombie->IsDie() && !warrior->IsDie())
        {
            input = getchar();
            if (input == 'e')
                break;
            
            warrior->Fight(zombie);
            warrior->stats->ShowStats();
        }
    }
    
    return 0;
}