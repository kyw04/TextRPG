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
    while (!game_manager->player->IsDie())
    {
        game_manager->map->Open();
        TileState tile = game_manager->Move();
        game_manager->PlayEvent(tile);
    }
    std::cout << "플레이어가 사망하였습니다.\n";

    return 0;
}