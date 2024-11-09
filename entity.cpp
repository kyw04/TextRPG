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

Skill& Entity::SelectSkill()
{
    char input;
    std::size_t index = 0;
    
    for (std::size_t i = 0; i < MAX_SKILL_COUNT; i++)
    {
        if (i % 2 == 0)
            std::cout << '\n';
        
        std::cout << skills[i] << " ";
    }

    while (true)
    {
        INPUT_KEY(input)
        if (!input)
            break;
        
        if (IF_UP_KEY(input)) { index += MAX_SKILL_COUNT / 2; }
        if (IF_DOWN_KEY(input)) { index -= MAX_SKILL_COUNT / 2; }
        if (IF_LEFT_KEY(input)) { index--; }
        if (IF_RIGHT_KEY(input)) { index++; }
        index %= MAX_SKILL_COUNT;
        
        std::cout << '\n'; std::cout << '\n';
        for (std::size_t i = 0; i < MAX_SKILL_COUNT; i++)
        {
            if (i % (MAX_SKILL_COUNT / 2) == 0)
                std::cout << '\n';
            
            if (index == i)
                std::cout << "<<" << skills[i] << ">> ";
            else
                std::cout << skills[i] << " ";
        }
    }

    return skills[index];
}

void Entity::AddSkill(Skill _skill)
{
    if (skill_count >= MAX_SKILL_COUNT) { ChangeSkill(_skill); }
    else { skills[skill_count++] = _skill; }
}

void Entity::ChangeSkill(Skill _new_skill)
{
    std::cout << "새로운 스킬: " << _new_skill;
    Skill& old_skill = SelectSkill();
    old_skill = _new_skill;
}