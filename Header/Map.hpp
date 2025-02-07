#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include "Stage.hpp"
#include "Define.hpp"
#include "EnumClass.hpp"

struct Point
{
    int x;
    int y;
};

class Map : public Stage
{
private:
    std::vector<std::pair<TileStateEnum, double>> tile_probability = // 타일 클래스나 구조체 만들어서 이벤트도 가지고 있게 하면 좋을 듯
    {
        { TileStateEnum::Wall, 0.6 }, // 벽이 가장 위에 있어야 함
        { TileStateEnum::Monster, 0.4 },
        { TileStateEnum::Treasure, 0.05 },
        { TileStateEnum::Trap, 0.05 }
    };
    double total_tile_probability;
    std::string seed;

public:
    bool is_open;
    TileStateEnum tiles[MAX_MAP_SIZE][MAX_MAP_SIZE];
    Point player_position;

    friend std::ostream& operator<<(std::ostream&, Map&);

    Map();
    Map(Stage&);
    ~Map();

    bool IsPointInside(int, int);
    char GetTileSymbol(const TileStateEnum&);
    TileStateEnum GetRandomTile(int = -1);
    void TileSetting();
    void Open();
    void Close();
    void Copy(Stage&);
    void Clear(Stage&);
    std::string GetSeed();
};