#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Entity/Entity.hpp"
#include "Entity/Player/Archer.hpp"
#include "Entity/Player/Warrior.hpp"
#include "Entity/Player/Wizard.hpp"
#include "Entity/Zombie.hpp"
#include "Entity/Goblin.hpp"
#include "Entity/GoblinKing.hpp"
#include "Entity/GoblinArcher.hpp"
#include "Entity/GoblinWarrior.hpp"
#include "Entity/GoblinWizard.hpp"
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
    std::vector<Entity> monster_data[MAX_LEVEL] = // enemty[level][enemy index] 
    { 
        { Goblin() }, // level == 1
        { }, // level == 2
        { GoblinArcher(), GoblinWarrior(), GoblinWizard() }, // level == 3
        { }, // level == 4
        { Zombie() }, // level == 5
    };
    std::vector<Entity> boss_data[MAX_LEVEL] = // enemty[level][enemy] 
    { 
        {GoblinKing() }, // stage == 1
        { Zombie() } // stage == 2
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
    TileStateEnum Move(const char);
    Entity GetRandomEntity(const int, const int, std::vector<Entity>[]);
    void PlayEvent(const TileStateEnum);
};