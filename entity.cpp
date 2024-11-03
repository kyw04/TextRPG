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

void Attack(Entity* _attacker, Entity* _defender)
{
    float damage;
    std::cout << _attacker->name << "의 공격\n";
    std::cout << _defender->name << "에게 ";
    damage = _attacker->stats->GetDamage(_attacker->attack_type);
    std::cout << damage << "의 데미지를 입힘\n";
    _defender->TakeDamage(_attacker->attack_type, damage);
    if (!_defender->IsDie())
        std::cout << _defender->name << " 체력: " << _defender->stats->GetHealth() << '\n';
    std::cout << '\n';
}

void Entity::Fight(Entity* _enemy)
{
    float my_attack_speed = stats->GetAttackSpeed();
    float _enemy_attack_speed = _enemy->stats->GetAttackSpeed();
    Entity* first;
    Entity* second;

    if (my_attack_speed >= _enemy_attack_speed)
    {
        first = this;
        second = _enemy;
    }
    else
    {
        first = _enemy;
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