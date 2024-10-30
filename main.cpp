#include <iostream>
#include "./Header/Stats.hpp"
#include "./Header/Entity/Entity.hpp"
#include "./Header/Entity/Warrior.hpp"
#include "./Header/Entity/Zombie.hpp"
#include "./Header/Item/Item.hpp"
#include "./Header/Item/WoodSword.hpp"
#include "./Header/Inventory.hpp"

int main()
{
    int input;
    Warrior *warrior = new Warrior();
    while (!warrior->IsDie())
    {
        Zombie* zombie = new Zombie();
        Inventory* inventory = new Inventory();
        inventory->Push(new WoodSword());
        
        while (!zombie->IsDie() && !warrior->IsDie())
        {
            input = getchar();
            if (input == 'e')
                break;
            
            inventory->ShowInventory();
        }
    }
    
    return 0;
}