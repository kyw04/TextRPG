#pragma once
#include <string>
#include "Define.hpp"

class Stage
{
protected:
    std::string name;
    int level;
    int monster_max_level;
    int monster_min_level;
    int height;
    int width;

public:
    Stage();
    Stage(std::string, int, int, int, int, int);
    ~Stage();

    void Clear(Stage&);
};