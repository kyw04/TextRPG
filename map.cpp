#include "./Header/Map.hpp"

std::ostream& operator<<(std::ostream& _out, Map& _map)
{
    for (int i = 0; i < _map.height; i++)
    {
        for (int j = 0; j < _map.width; j++)
        {
            if (i == _map.current_position.first && j == _map.current_position.second)
                std::cout << "<p>"; 
            else
                std::cout << ' ' << _map.GetTileSymbol(_map.tiles[i][j]) << ' '; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    return _out;
}

Map::Map(int _heigth, int _width) : 
    height(_heigth > MAX_MAP_SIZE ? MAX_MAP_SIZE : _heigth),
    width(_width > MAX_MAP_SIZE ? MAX_MAP_SIZE : _width),
    current_position({ height - 1, width / 2 })
{
    total_tile_probability = 0;
    for (auto& probability : tile_probability)
        total_tile_probability += probability.second;
     
    TileSetting();
}

char Map::GetTileSymbol(const TileState& _tile)
{
    switch (_tile)
    {
        case TileState::Wall: return '#';
        case TileState::Empty: return '.';
        case TileState::Monster: return 'E';
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
    std::uniform_real_distribution<> dis(0.0, total_tile_probability);

    int move_x[4] = { 1, -1, 0, 0 };
    int move_y[4] = { 0, 0, 1, -1 };
    int current_x = width / 2;
    int current_y = height - 1;

    for (auto& i : tiles)
        for (auto& j : i)
            j = TileState::None;

    std::queue<std::pair<int, int>> q;
    tiles[current_y][current_x - 1] = TileState::Wall;
    tiles[current_y][current_x + 1] = TileState::Wall;
    tiles[current_y--][current_x] = TileState::Empty;
    tiles[current_y][current_x] = TileState::Monster;
    q.push({ current_x, current_y });
    while (!q.empty())
    {
        current_x = q.front().first;
        current_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = current_x + move_x[i];
            int new_y = current_y + move_y[i];
            if (new_x < width && new_x >= 0 && new_y < height && new_y >= 0 && tiles[new_y][new_x] == TileState::None)
            {
                double random_value = dis(gen);
                double cumulative = 0.0;
                for (auto& tile : tile_probability)
                {
                    cumulative += tile.second;
                    if (random_value <= cumulative)
                    {
                        tiles[new_y][new_x] = tile.first;
                        break;
                    }
                }

                if (tiles[new_y][new_x] != TileState::Wall)
                    q.push({ new_x, new_y });
            }
        }
    }
}

void Map::Open()
{
    is_open = true;
    std::cout << "맵 열림\n";
    std::cout << *this;

    
}

void Map::Close()
{
    is_open = false;
    std::cout << "맵 닫힘\n";
}