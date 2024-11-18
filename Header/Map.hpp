#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include "Define.hpp"
#include "EnumClass.hpp"

class Map
{
private:
    const std::vector<std::pair<TileState, double>> tile_probability = // 타일 클래스나 구조체 만들어서 이벤트도 가지고 있게 하면 좋을 듯
    {
        { TileState::Wall, 0.3 },
        { TileState::Monster, 0.4 },
        { TileState::Treasure, 0.05 },
        { TileState::Trap, 0.05 }
    };
    double total_tile_probability;
    

public:
    bool is_open;
    int height;
    int width;
    TileState tiles[MAX_MAP_SIZE][MAX_MAP_SIZE];
    std::pair<int, int> current_position;

    friend  std::ostream& operator<<(std::ostream&, Map&);

    Map(int = MAX_MAP_SIZE, int = MAX_MAP_SIZE);
    char GetTileSymbol(const TileState&);
    void TileSetting();
    void Open();
    void Close();
};