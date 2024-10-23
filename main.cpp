#include <iostream>
#include "./Header/Stats.h"
#include "./Header/Entity/Entity.h"
#include "./Header/Entity/Warrior.h"

int main()
{
    int input;
    Warrior warrior;
    while (!warrior.IsDie())
    {
        input = getchar();
        if (input == 'e')
            break;

        warrior.TakeDamage(10);
        warrior.ShowStats();
        
    }
    
    return 0;
}