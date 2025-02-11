#include "./Header/GameManager.hpp"

GameManager::GameManager()
{
    std::cout << "<<입력으로 게임 시작>>\n";
    INPUT_KEY();

    player = SelectPlayer();
    map = new Map(stage_data[0]);
    
    // Item* start_item;
    switch (player->job.value)
    {
        case EntityJobEnum::Warrior:
            // start_item = new WoodSword();
            break;
        case EntityJobEnum::Archer:
            // start_item = new WoodBow();
            break;
        case EntityJobEnum::Wizard:
            // start_item = new WoodStaff();
            break;
        default:
        {
            // start_item = nullptr;
        }
    }
    // player->Push(new WoodBow());
}

Player* GameManager::SelectPlayer()
{
    std::vector<Player*> players = { new Warrior(), new Archer(), new Wizard() };
    int input = '\a';
    int index = 0;
    std::cout << "== 직업 선택 ==\n";
    for (auto iter = players.begin(); iter != players.end(); iter++)
    {
        if (iter - players.begin() == index)
            std::cout << "<<" << (*iter)->name << ">>\n";
        else
            std::cout << (*iter)->name << '\n';
    }
    std::cout << '\n';

    while (true)
    {
        input = INPUT_KEY();
        if (IS_ENTER_KEY(input)) break;
        if (IS_UP_KEY(input)) { index--; }
        if (IS_DOWN_KEY(input)) { index++; }
        if (index < 0) { index = (int)players.size() - 1; }
        index %= (int)players.size();
        std::cout << "== 직업 선택 ==\n";
        for (std::vector<Player*>::iterator iter = players.begin(); iter != players.end(); iter++)
        {
            if (iter - players.begin() == index)
                std::cout << "<<" << (*iter)->name << ">>\n";
            else
                std::cout << (*iter)->name << '\n';
        }
        std::cout << '\n';
    }

    std::cout << players[(std::size_t)index]->name << "(이)가 선택 되었습니다.\n";
    while (!IS_ENTER_KEY(INPUT_KEY())) { }
    return players[(std::size_t)index];
}

TileStateEnum GameManager::Move(const int _input)
{
    if (!map->is_open)
        return TileStateEnum::Empty;
    
    TileStateEnum result = TileStateEnum::Empty;
    
    if (IS_CLOSE_KEY(_input)) { map->Close(); return result; }

    int x = 0;
    int y = 0;
    if (IS_UP_KEY(_input)) { y = -1; }
    if (IS_DOWN_KEY(_input)) { y = 1; }
    if (IS_LEFT_KEY(_input)) { x = -1; }
    if (IS_RIGHT_KEY(_input)) { x = 1; }

    int new_y = map->player_position.y + y;
    int new_x = map->player_position.x + x;
    if (new_y >= map->height) { new_y = map->height - 1; }
    if (new_y < 0) { new_y = 0; }
    if (new_x >= map->width) { new_x = map->width - 1; }
    if (new_x < 0) { new_x = 0; }

    if (map->tiles[new_x][new_y] != TileStateEnum::Wall)
    {
        map->player_position = { new_x, new_y };
        result = map->tiles[new_x][new_y];
    }
    // std::cout << *map;

    if (result != TileStateEnum::Empty)
        map->Close();
    
    return result;
}

Entity GameManager::GetRandomEntity(const int _min_level, const int _max_level, std::vector<Entity> _datas[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> random_level_dis((std::size_t)(_min_level - 1), (std::size_t)(_max_level - 1));
    std::size_t random_level = random_level_dis(gen);
    while (_datas[random_level].empty()) { random_level--; } // 찾은 레벨의 몬스터가 없는 경우 레벨을 낮추면서 찾음

    std::uniform_int_distribution<std::size_t> random_index_dis(0, _datas[random_level].size() - 1);
    std::size_t random_index = random_index_dis(gen);

    return _datas[random_level][random_index];
}

void GameManager::PlayEvent(const TileStateEnum _tile)
{
    switch (_tile)
    {
    case TileStateEnum::Monster:
    {
        Entity monster = GetRandomEntity(map->monster_min_level, map->monster_max_level, monster_data);
        std::cout << monster.name << "(을)를 만났습니다.\n\n";
        while (!player->IsDie() && !monster.IsDie()) { player->Fight(monster); }
        break;
    }
    case TileStateEnum::Boss:
    {
        Entity monster = GetRandomEntity(map->level, map->level, boss_data);
        std::cout << monster.name << "(을)를 만났습니다.\n\n";
        while (!player->IsDie() && !monster.IsDie()) { player->Fight(monster); }
        if (!player->IsDie()) { map->Clear(stage_data[(std::size_t)map->level]); }
        break;
    }
    
    case TileStateEnum::Trap:
    {
        std::cout << "함정을 발견했습니다.\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> random_damage_dis(1, 3);
        int random_damage = random_damage_dis(gen);
        std::cout << random_damage * 10 << "의 피해를 입었습니다\n";
        player->TakeDamage(new Entity("함정"), (float)random_damage * -10.0f);
        if (!player->IsDie())
            player->stats.ShowHealth();
        while (!IS_ENTER_KEY(INPUT_KEY())) { }
        break;
    }
    case TileStateEnum::Treasure:
    {
        std::cout << "보물상자를 발견했습니다.\n";
        for (auto& item : random_item_data.GetRandomItems()) { player->Push(item); }
        while (!IS_ENTER_KEY(INPUT_KEY())) { }
        break;
    }
    default:
        break;
    }

    int x = map->player_position.x;
    int y = map->player_position.y;
    map->tiles[x][y] = TileStateEnum::Empty;
}