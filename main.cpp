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
        if (IF_INVENTORY_KEY(input))
        {
            game_manager->player->Open();
            game_manager->player->StatsUpdate();
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