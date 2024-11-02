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

        while (!zombie->IsDie() && !warrior->IsDie())
        {
            input = getchar();
            if (input == 'e')
                break;

            inventory->Push(new WoodSword(), 5);
            std::cout << *inventory;
        }
    }
    
    return 0;
}