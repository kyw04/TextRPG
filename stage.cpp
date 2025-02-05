#include "./Header/Stage.hpp"

Stage::Stage() : 
    name("None"),
    height(MAX_MAP_SIZE),
    width(MAX_MAP_SIZE),
    level(1), monster_min_level(1), monster_max_level(1)
{

}

Stage::Stage(std::string _name, int _height, int _width, int _level, int _min, int _max) : 
    name(_name),
    height(_height > MAX_MAP_SIZE ? MAX_MAP_SIZE : _height),
    width(_width > MAX_MAP_SIZE ? MAX_MAP_SIZE : _width),
    level(_level), monster_min_level(_min), monster_max_level(_max)
{
    
}

Stage::~Stage()
{

}

std::string Stage::GetName()
{
    return this->name;
}