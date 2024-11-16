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
    const std::vector<std::pair<TileState, double>> tile_probability =
    {
        { TileState::Wall, 0.4 },
        { TileState::Entity, 0.3 },
        { TileState::Treasure, 0.05 },
        { TileState::Trap, 0.05 }
    };
    double total_tile_probability;

    TileState map[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int height;
    int width;

public:
    friend  std::ostream& operator<<(std::ostream&, Map&);

    Map(int = MAX_MAP_SIZE, int = MAX_MAP_SIZE);
    char GetTileSymbol(const TileState&);
    void TileSetting();
};