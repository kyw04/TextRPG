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
#include "./Header/GameManager.hpp"
#include "./Header/Skill/Skill.hpp"

int main()
{
    GameManager* game_manager = new GameManager();
    while (true)
    {
        game_manager->map->Open();
        TileState tile = game_manager->Move();
        game_manager->PlayEvent(tile);
    }

    return 0;
}