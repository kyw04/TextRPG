#pragma once
#include <iostream>
#include <vector>
#include "Entity/Entity.hpp"
#include "Entity/Archer.hpp"
#include "Entity/Warrior.hpp"
#include "Entity/Wizard.hpp"
#include "Entity/Zombie.hpp"
#include "Item/Item.hpp"
#include "Item/WoodBow.hpp"
#include "Item/WoodSword.hpp"
#include "Skill/Skill.hpp"
#include "Define.hpp"
#include "EnumClass.hpp"
#include "Inventory.hpp"
#include "Map.hpp"
#include "Stats.hpp"

class GameManager
{
private:
    std::vector<std::vector<Entity*>> monster = // enemty[level][enemy] 
    { 
        { new Zombie() }, // level == 1
        { new Zombie() } // level == 2
    };

public:
    Entity* player;
    Inventory* inventory;
    Map* map;

    GameManager();
    Entity* SelectPlayer();
    TileState Move();
};