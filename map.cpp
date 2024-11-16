#include "./Header/Map.hpp"

std::ostream& operator<<(std::ostream& _out, Map& _map)
{
    for (int i = 0; i < _map.height; i++)
    {
        for (int j = 0; j < _map.width; j++)
        {
            std::cout << ' ' << _map.GetTileSymbol(_map.map[i][j]) << ' '; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    return _out;
}


Map::Map(int _heigth, int _width) : 
    height(_heigth > MAX_MAP_SIZE ? MAX_MAP_SIZE : _heigth),
    width(_width > MAX_MAP_SIZE ? MAX_MAP_SIZE : _width)
{
    TileSetting();
}

char Map::GetTileSymbol(const TileState& _tile)
{
    switch (_tile)
    {
        case TileState::Wall: return '#';
        case TileState::Empty: return '.';
        case TileState::Entity: return 'E';
        case TileState::Boss: return 'B';
        case TileState::Treasure: return '?';
        case TileState::Trap: return '?';
        default: return ' ';
    }
}

void Map::TileSetting()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dis(0, 1);
    // std::uniform_int_distribution<unsigned int> dis(0, (int)TileState::None);

    int move_x[3] = { 1, 0, -1 };
    int move_y[3] = { -1, 0, 1 };
    int current_x = width / 2;
    int current_y = height - 1;

    for (auto& i : map)
        for (auto& j : i)
            j = TileState::None;

    std::queue<std::pair<int, int>> q;
    map[current_y][current_x - 1] = TileState::Wall;
    map[current_y][current_x + 1] = TileState::Wall;
    map[current_y--][current_x] = TileState::Empty;
    map[current_y][current_x] = TileState::Empty;
    q.push({ current_x, current_y });
    while (!q.empty())
    {
        current_x = q.front().first;
        current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (move_x[i] * move_x[i] == move_y[j] * move_y[j])
                    continue;
                
                int new_x = current_x + move_x[i];
                int new_y = current_y + move_y[j];
                if (new_x < width && new_x >= 0 && new_y < height && new_y >= 0 && map[new_y][new_x] == TileState::None)
                {
                    map[new_y][new_x] = (TileState)dis(gen);
                    if (map[new_y][new_x] != TileState::Wall)
                        q.push({ new_x, new_y });
                }
            }
        }
    }
    
}