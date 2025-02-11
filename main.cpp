#include <iostream>
#include "./Header/GameManager.hpp"

int main()
{
    GameManager* game_manager = new GameManager();
    int input;
    while (!game_manager->player->IsDie())
    {
        game_manager->map->Open();
        if (IS_INVENTORY_KEY(input))
        {
            game_manager->player->Open();
            game_manager->player->StatsUpdate();
        }
        else if (input == 'o')
        {
            game_manager->player->AddStat();
        }
        else
        {
            TileStateEnum tile = game_manager->Move(input);
            std::cout << game_manager->player->name << '\n';
            game_manager->player->stats.ShowHealth();
            std::cout << *game_manager->map;
            game_manager->PlayEvent(tile);
        }

        std::cout << game_manager->player->name << '\n';
        game_manager->player->stats.ShowHealth();
        std::cout << *game_manager->map;
        
        input = 0;
        input = INPUT_KEY();
    }
    std::cout << "플레이어가 사망하였습니다.\n";

    return 0;
}