#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Entity/Entity.hpp"
#include "Entity/Player/Archer.hpp"
#include "Entity/Player/Warrior.hpp"
#include "Entity/Player/Wizard.hpp"
#include "Entity/Zombie.hpp"
#include "Item/Item.hpp"
#include "Item/WoodBow.hpp"
#include "Item/WoodSword.hpp"
#include "Item/WoodStaff.hpp"
#include "Skill/Skill.hpp"
#include "Define.hpp"
#include "EnumClass.hpp"
#include "Inventory.hpp"
#include "Map.hpp"
#include "Stats.hpp"

class GameManager
{
private:
    std::vector<Entity> monster_data[MAX_LEVEL] = // enemty[level][enemy] 
    { 
        { Zombie(), Zombie() }, // level == 1
        { Zombie() } // level == 2
    };
    std::vector<Entity> boss_data[MAX_LEVEL] = // enemty[level][enemy] 
    { 
        { Zombie(), Zombie() }, // level == 1
        { Zombie() } // level == 2
    };
    std::vector<Item> random_item_data = 
    {
        WoodBow(),
        WoodSword(),
        WoodStaff()
    };

public:
    Player* player;
    Map* map;

    GameManager();
    Player* SelectPlayer();
    TileState Move(const char);
    Entity GetRandomEntity(const int, const int, std::vector<Entity>[]);
    void PlayEvent(const TileState);
};