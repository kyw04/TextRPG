#include "./Header/Stage.hpp"

Stage::Stage() : 
    name("None"),
    level(1), monster_max_level(1), monster_min_level(1),
    height(MAX_MAP_SIZE),
    width(MAX_MAP_SIZE)
{

}

Stage::Stage(std::string _name, int _level, int _max, int _min, int _height, int _width) : 
    name(_name),
    level(_level), monster_max_level(_max), monster_min_level(_min),
    height(_height > MAX_MAP_SIZE ? MAX_MAP_SIZE : _height),
    width(_width > MAX_MAP_SIZE ? MAX_MAP_SIZE : _width)
{
    
}

Stage::~Stage()
{

}

void Stage::Clear(Stage& _next_stage)
{
    this->name = _next_stage.name;
    this->level = _next_stage.level;
    this->monster_max_level = _next_stage.monster_max_level;
    this->monster_min_level = _next_stage.monster_min_level;
    this->height = _next_stage.height;
    this->width = _next_stage.width;
}