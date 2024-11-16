#pragma once
#include <iostream>
#include <random>
#include <queue>
#include "Define.hpp"
#include "EnumClass.hpp"

class Map
{
private:
    TileState map[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int height;
    int width;

public:
    friend  std::ostream& operator<<(std::ostream&, Map&);

    Map(int = MAX_MAP_SIZE, int = MAX_MAP_SIZE);
    char GetTileSymbol(const TileState&);
    void TileSetting();
};