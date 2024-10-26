#include <iostream>
#include "./Header/Entity/Entity.hpp"

Entity::Entity() : is_die(false) {}

void Entity::TakeDamage(Stats::AttackType _attack_type, float _value)
{
    float damage = stats->SetDamage(_attack_type, _value);
    if (this->stats->AddHealth(damage) <= 0)
    {
        Die();
    }
}

void Entity::Fight(Entity* enemy)
{
    float my_attack_speed = stats->GetAttackSpeed();
    float enemy_attack_speed = enemy->stats->GetAttackSpeed();
    Entity* first_attack_entity;
    Entity* second_attack_entity;

    if (my_attack_speed >= enemy_attack_speed)
    {
        first_attack_entity = this;
        second_attack_entity = enemy;
    }
    else
    {
        first_attack_entity = enemy;
        second_attack_entity = this;
    }

    float damage;
    std::cout << first_attack_entity->name << "의 공격\n";
    std::cout << second_attack_entity->name << "에게 ";
    damage = first_attack_entity->stats->GetDamage(first_attack_entity->attack_type);
    std::cout << damage << "의 데미지를 입힘\n";
    second_attack_entity->TakeDamage(first_attack_entity->attack_type, damage);
    if (!second_attack_entity->IsDie())
    {
        std::cout << second_attack_entity->name << "의 공격\n";
        std::cout << first_attack_entity->name << "에게 ";
        damage = second_attack_entity->stats->GetDamage(second_attack_entity->attack_type); 
        std::cout << damage << "의 데미지를 입힘\n";
        first_attack_entity->TakeDamage(second_attack_entity->attack_type, damage);
    }
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