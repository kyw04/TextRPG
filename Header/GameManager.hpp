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
    Entity monster_data[MAX_LEVEL][4] = // enemty[level][enemy] 
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
    Entity GetRandomMonster(const int, const int);
    void PlayEvent(const TileState);
};