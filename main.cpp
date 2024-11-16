#include <iostream>
#include "./Header/Stats.hpp"
#include "./Header/Entity/Entity.hpp"
#include "./Header/Entity/Warrior.hpp"
#include "./Header/Entity/Zombie.hpp"
#include "./Header/Item/Item.hpp"
#include "./Header/Item/WoodSword.hpp"
#include "./Header/Inventory.hpp"
#include "./Header/Define.hpp"
#include "./Header/Map.hpp"
#include "./Header/Skill/Skill.hpp"

int main()
{
    Map* map = new Map();
    std::cout << *map;
    
    return 0;
}