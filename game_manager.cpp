#include "./Header/GameManager.hpp"

GameManager::GameManager()
{
    std::cout << "<<입력으로 게임 시작>>";
    char input;
    INPUT_KEY(input);
    if (IF_DOWN_KEY(input))
        return;

    player = SelectPlayer();
    map = new Map();
}

Entity* GameManager::SelectPlayer()
{
    std::vector<Entity*> players = { new Warrior(), new Archer(), new Wizard() };
    char input = '\a';
    int index = 0;
    for (auto iter = players.begin(); iter != players.end(); iter++)
    {
        if (iter - players.begin() == index)
            std::cout << "<<" << (*iter)->name << ">>\n";
        else
            std::cout << (*iter)->name << '\n';
    }

    while (true)
    {
        INPUT_KEY(input);
        if (!input) break;
        if (IF_UP_KEY(input)) { index--; }
        if (IF_DOWN_KEY(input)) { index++; }
        if (index < 0) { index = (int)players.size() - 1; }
        index %= (int)players.size();
        for (std::vector<Entity*>::iterator iter = players.begin(); iter != players.end(); iter++)
        {
            if (iter - players.begin() == index)
                std::cout << "<<" << (*iter)->name << ">>\n";
            else
                std::cout << (*iter)->name << '\n';
        }
    }

    std::cout << players[(std::size_t)index]->name << "가 선택 되었습니다.\n";
    return players[(std::size_t)index];
}

TileState GameManager::Move()
{
    TileState result = TileState::Empty;
    char input;
    while (map->is_open)
    {
        INPUT_KEY(input);
        if (IF_CLOSE_KEY(input)) { map->Close(); return result; }

        int x = 0;
        int y = 0;
        if (IF_UP_KEY(input)) { y = -1; }
        if (IF_DOWN_KEY(input)) { y = 1; }
        if (IF_LEFT_KEY(input)) { x = -1; }
        if (IF_RIGHT_KEY(input)) { x = 1; }

        int new_y = map->current_position.first + y;
        int new_x = map->current_position.second + x;
        if (new_y >= MAX_MAP_SIZE) { new_y = MAX_MAP_SIZE - 1; }
        if (new_y < 0) { new_y = 0; }
        if (new_x >= MAX_MAP_SIZE) { new_x = MAX_MAP_SIZE - 1; }
        if (new_x < 0) { new_x = 0; }

        if (map->tiles[new_y][new_x] != TileState::Wall)
        {
            map->current_position = { new_y, new_x };
            result = map->tiles[new_y][new_x];
        }
        std::cout << *map;

        if (result != TileState::Empty)
            map->Close();
    }
    
    return result;
}

Entity GameManager::GetRandomMonster(const int _min_level, const int _max_level)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> random_level_dis((std::size_t)(_min_level - 1), (std::size_t)(_max_level - 1));
    std::size_t random_level = random_level_dis(gen);
    std::uniform_int_distribution<std::size_t> random_index_dis(0, monster_data[random_level].size() - 1);
    std::size_t random_index = random_index_dis(gen);

    return monster_data[random_level][random_index];
}

void GameManager::PlayEvent(const TileState _tile)
{
    switch (_tile)
    {
    case TileState::Entity: case TileState::Boss:
    {
        Entity monster = GetRandomMonster(1, 1);
        while (!player->IsDie() && !monster.IsDie()) { player->Fight(monster); }
        break;
    }
    case TileState::Trap:
    {
        player->TakeDamage(AttackType::Intelligence, 5.0f);
        player->TakeDamage(AttackType::Strength, 5.0f);
        break;
    }
    case TileState::Treasure:
    {
        break;
    }
    default:
        break;

    }

    int x = map->current_position.first;
    int y = map->current_position.second;
    map->tiles[x][y] = TileState::Empty;
}