#include <iostream>
#include "./Header/Stats.hpp"
#include "./Header/Entity/Entity.hpp"
#include "./Header/Entity/Warrior.hpp"
#include "./Header/Entity/Zombie.hpp"
#include "./Header/Item/Item.hpp"
#include "./Header/Item/WoodSword.hpp"
#include "./Header/Inventory.hpp"
#include "./Header/Define.hpp"

int main()
{
    char input;
    Warrior* warrior = new Warrior();
    Inventory* inventory = new Inventory();
    while (!warrior->IsDie())
    {
        INPUT_KEY(input);
    }
    
    return 0;
}