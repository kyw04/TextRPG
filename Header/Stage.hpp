#pragma once
#include <string>
#include "Define.hpp"

class Stage
{
protected:
    std::string name;

public:
    int height;
    int width;

    int level;
    int monster_min_level;
    int monster_max_level;

    Stage();
    Stage(std::string, int, int, int, int, int);
    ~Stage();

    std::string GetName();
};