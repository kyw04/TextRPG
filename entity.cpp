#include <iostream>
#include "./Header/Entity/Entity.hpp"

Entity::Entity() : is_die(false) {}

void Entity::TakeDamage(AttackType _attack_type, float _value)
{
    float damage = stats->SetDamage(_attack_type, _value);
    if (this->stats->AddHealth(damage) <= 0)
    {
        Die();
    }
}

void Attack(Entity* first, Entity* second)
{
    float damage;
    std::cout << first->name << "의 공격\n";
    std::cout << second->name << "에게 ";
    damage = first->stats->GetDamage(first->attack_type);
    std::cout << damage << "의 데미지를 입힘\n";
    second->TakeDamage(first->attack_type, damage);
    if (!second->IsDie())
        std::cout << second->name << " 체력: " << second->stats->GetHealth() << '\n';
    std::cout << '\n';
}

void Entity::Fight(Entity* enemy)
{
    float my_attack_speed = stats->GetAttackSpeed();
    float enemy_attack_speed = enemy->stats->GetAttackSpeed();
    Entity* first;
    Entity* second;

    if (my_attack_speed >= enemy_attack_speed)
    {
        first = this;
        second = enemy;
    }
    else
    {
        first = enemy;
        second = this;
    }

    Attack(first, second);
    if (!second->IsDie()) Attack(second, first);
    
}

void Entity::Die()
{
    is_die = true;
    std::cout << name << " 죽음\n";
}

bool Entity::IsDie()
{
    return is_die;
}