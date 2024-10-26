#include <iostream>
#include "./Header/Stats.hpp"
#include "./Header/Entity/Entity.hpp"
#include "./Header/Entity/Warrior.hpp"

int main()
{
    int input;
    Warrior *warrior = new Warrior();
    while (!warrior->IsDie())
    {
        input = getchar();
        if (input == 'e')
            break;

        warrior->TakeDamage(10);
        warrior->stats->ShowStats();
        
    }
    
    return 0;
}