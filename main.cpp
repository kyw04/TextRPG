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
    char input;
    while (!game_manager->player->IsDie())
    {
        game_manager->map->Open();
        INPUT_KEY(input);
        if (IF_INVENTORY_KEY(input))
        {
            game_manager->inventory->Open();
        }    
        else
        {
            TileState tile = game_manager->Move(input);
            game_manager->PlayEvent(tile);
        }
    }
    std::cout << "플레이어가 사망하였습니다.\n";

    return 0;
}