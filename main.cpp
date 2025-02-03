#include <iostream>
#include "./Header/GameManager.hpp"

int main()
{
    GameManager* game_manager = new GameManager();
    char input;
    while (!game_manager->player->IsDie())
    {
        game_manager->map->Open();
        INPUT_KEY(input);
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
            game_manager->PlayEvent(tile);
        }
    }
    std::cout << "플레이어가 사망하였습니다.\n";

    return 0;
}