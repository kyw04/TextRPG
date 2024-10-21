#include <iostream>
#include "./Header/Entity.h"

Entity::Entity(Type _type): type(_type)
{

}

void Entity::ShowEntity()
{
    std::cout << "타입\t\t[" << type << "]\n";
    Stats::ShowStats();
}