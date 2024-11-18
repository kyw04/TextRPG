#pragma once
#include <iostream>
#include <vector>
#include <random>
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

public:
    Entity* player;
    Inventory* inventory;
    Map* map;

    GameManager();
    Entity* SelectPlayer();
    TileState Move();
    Entity GetRandomEntity(const int, const int, std::vector<Entity>[]);
    void PlayEvent(const TileState);
};