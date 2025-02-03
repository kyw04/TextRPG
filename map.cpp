#include "./Header/Map.hpp"

std::ostream& operator<<(std::ostream& _out, Map& _map)
{
    for (int y = 0; y < _map.height; y++)
    {
        for (int x = 0; x < _map.width; x++)
        {
            if (y == _map.current_position.y && x == _map.current_position.x)
                std::cout << "<p>"; 
            else
                std::cout << ' ' << _map.GetTileSymbol(_map.tiles[x][y]) << ' '; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    return _out;
}

Map::Map(int _heigth, int _width) : 
    height(_heigth > MAX_MAP_SIZE ? MAX_MAP_SIZE : _heigth),
    width(_width > MAX_MAP_SIZE ? MAX_MAP_SIZE : _width),
    current_position({ width / 2, height - 1 })
{
    TileSetting();
}

bool Map::IsPointInside(int _x, int _y)
{
    return _x < width && _x >= 0 && _y < height && _y >= 0;
}

char Map::GetTileSymbol(const TileStateEnum& _tile)
{
    switch (_tile)
    {
        case TileStateEnum::Wall: return '#';
        case TileStateEnum::Empty: return '.';
        case TileStateEnum::Monster: return 'E';
        case TileStateEnum::Boss: return 'B';
        case TileStateEnum::Treasure: return '?';
        case TileStateEnum::Trap: return '?';
        default: return ' ';
    }
}

TileStateEnum Map::GetRandomTile(int _mask)
{
    std::vector<std::pair<TileStateEnum, double>> mask_tiles;
    total_tile_probability = 0.0;
    for (auto& tile : tile_probability)
    {
        if ((int)tile.first & _mask)
        {
            total_tile_probability += tile.second;
            mask_tiles.push_back(tile);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, total_tile_probability);

    double random_value = dis(gen);
    double cumulative = 0.0;
    for (auto& tile : mask_tiles)
    {
        cumulative += tile.second;
        if (random_value <= cumulative)
        {
            return tile.first;
        }
    }

    return TileStateEnum::Empty;
}

double GetDistance(Point _a, Point _b)
{
    return (_a.x - _b.x) * (_a.x - _b.x) + (_a.y - _b.y) * (_a.y - _b.y);
}

void Map::TileSetting()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, total_tile_probability);

    int move_x[4] = { 1, -1, 0, 0 };
    int move_y[4] = { 0, 0, 1, -1 };
    int start_x = width / 2;
    int start_y = height / 2; // height - 1;
    Point closest = { start_x, start_y };
    double closest_distance = GetDistance(current_position, closest);
    Point furthest = { start_x, start_y };
    double furthest_distance = 0;

    int current_x = start_x;
    int current_y = start_y;
    for (auto& i : tiles) for (auto& j : i) { j = TileStateEnum::None; }

    std::queue<Point> q;
    tiles[current_x][current_y] = GetRandomTile(~(int)TileStateEnum::Wall);
    if (tiles[current_x][current_y] == TileStateEnum::Wall) { current_y--; }
    q.push({ current_x, current_y });
    bool is_player_position_visited = false;
    while (!q.empty())
    {
        current_x = q.front().x;
        current_y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = current_x + move_x[i];
            int new_y = current_y + move_y[i];
            if (IsPointInside(new_x, new_y) && tiles[new_x][new_y] == TileStateEnum::None)
            {
                if (current_position.y == new_y && current_position.x == new_x)
                {
                    is_player_position_visited = true;
                    tiles[new_x][new_y] = TileStateEnum::Empty;
                    continue;
                }

                tiles[new_x][new_y] = GetRandomTile();

                if (tiles[new_x][new_y] != TileStateEnum::Wall)
                {
                    q.push({ new_x, new_y });
                    double new_distance = GetDistance(current_position, { new_x, new_y }); 
                    if ((new_distance > furthest_distance) || (new_distance == furthest_distance && (int)(dis(gen) * 10) % 2 == 0))
                    {
                        furthest = { new_x, new_y };
                        furthest_distance = new_distance;
                    }
                    if ((new_distance < closest_distance) || (new_distance == closest_distance && (int)(dis(gen) * 10) % 2 == 0))
                    {
                        closest = { new_x, new_y };
                        closest_distance = new_distance;
                    }
                }
            }
        }
    }

    q.push({ closest.x, closest.y });
    while (!is_player_position_visited)
    {
        current_x = closest.x;
        current_y = closest.y;
        
        for (int i = 0; i < 4; i++)
        {
            int new_x = current_x + move_x[i];
            int new_y = current_y + move_y[i];

            if (current_position.y == new_y && current_position.x == new_x)
            {
                is_player_position_visited = true;
            }

            if (IsPointInside(new_x, new_y))
            {
                double new_distance = GetDistance(current_position, { new_x, new_y });
                if ((new_distance < closest_distance) || (new_distance == closest_distance && (int)(dis(gen) * 10) % 2 == 0))
                {
                    tiles[closest.x][closest.y] = GetRandomTile(~(int)TileStateEnum::Wall);
                    q.push({ new_x, new_y });
                    closest = { new_x, new_y };
                    closest_distance = new_distance;
                }
            }
            
        }
    }

    q.push({ current_position.x, current_position.y });
    tile_probability[0].second *= 1.5; // Wall
    while (!q.empty())
    {
        current_x = q.front().x;
        current_y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = current_x + move_x[i];
            int new_y = current_y + move_y[i];
            if (IsPointInside(new_x, new_y) && tiles[new_x][new_y] == TileStateEnum::None)
            {
                tiles[new_x][new_y] = GetRandomTile();

                if (tiles[new_x][new_y] != TileStateEnum::Wall)
                {
                    q.push({ new_x, new_y });
                }
            }
        }
    }
    tile_probability[0].second /= 1.5; // Wall

    tiles[furthest.x][furthest.y] = TileStateEnum::Boss;
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