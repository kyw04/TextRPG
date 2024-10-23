#include <iostream>
#include "./Header/Entity/Entity.h"

Entity::Entity() : is_die(false) {}

void Entity::TakeDamage(float value)
{
    if (this->SetHealth(health - value) <= 0)
    {
        Die();
    }
}

void Entity::Die()
{
    is_die = true;
    std::cout << "Die\n";
}

bool Entity::IsDie()
{
    return is_die;
}