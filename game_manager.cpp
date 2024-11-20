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
    inventory = new Inventory();
    Item* start_item;
    switch (player->job)
    {
        case EntityJob::Warrior:
            start_item = new WoodSword();
            break;
        case EntityJob::Archer:
            start_item = new WoodBow();
            break;
        case EntityJob::Wizard:
            start_item = new WoodStaff();
            break;
        default:
            start_item = nullptr;
    }
    inventory->Push(start_item);
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

TileState GameManager::Move(const char _input)
{
    if (!map->is_open)
        return TileState::Empty;
    
    TileState result = TileState::Empty;
    
    if (IF_CLOSE_KEY(_input)) { map->Close(); return result; }

    int x = 0;
    int y = 0;
    if (IF_UP_KEY(_input)) { y = -1; }
    if (IF_DOWN_KEY(_input)) { y = 1; }
    if (IF_LEFT_KEY(_input)) { x = -1; }
    if (IF_RIGHT_KEY(_input)) { x = 1; }

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
    
    return result;
}

Entity GameManager::GetRandomEntity(const int _min_level, const int _max_level, std::vector<Entity> _datas[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> random_level_dis((std::size_t)(_min_level - 1), (std::size_t)(_max_level - 1));
    std::size_t random_level = random_level_dis(gen);
    std::uniform_int_distribution<std::size_t> random_index_dis(0, _datas[random_level].size() - 1);
    std::size_t random_index = random_index_dis(gen);

    return _datas[random_level][random_index];
}

void GameManager::PlayEvent(const TileState _tile)
{
    switch (_tile)
    {
    case TileState::Monster: case TileState::Boss:
    {
        Entity monster = GetRandomEntity(1, 1, _tile == TileState::Monster ? monster_data : boss_data);
        while (!player->IsDie() && !monster.IsDie()) { player->Fight(monster); }
        break;
    }
    
    case TileState::Trap:
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> random_damage_dis(10, 30);
        int random_damage = random_damage_dis(gen);
        player->TakeDamage(AttackType::None, (float)random_damage);
        std::cout << random_damage << "를 입음\n";
        if (!player->IsDie())
            std::cout << "남은 체력: " << player->stats.GetHealth() << '\n';
        char input;
        INPUT_KEY(input);
        if (IF_DOWN_KEY(input)) break;
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