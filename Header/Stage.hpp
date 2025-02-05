#pragma once
#include <string>
#include "Define.hpp"

class Stage
{
protected:
    std::string name;
    int height;
    int width;

public:
    int level;
    int monster_max_level;
    int monster_min_level;

    Stage();
    Stage(std::string, int, int, int, int, int);
    ~Stage();

    void Clear(Stage&);
};