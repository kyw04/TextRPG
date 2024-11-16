#include <iostream>
#include "./Header/Entity/Entity.hpp"

Entity::Entity() : is_die(false) {}

void Entity::TakeDamage(AttackType _attack_type, float _value)
{
    float damage = stats->SetDamage(_attack_type, _value);
    if (stats->AddHealth(damage) <= 0) { Die(); }
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
    float enemy_attack_speed = _enemy->stats->GetAttackSpeed();
    Entity* first = my_attack_speed >= enemy_attack_speed ? this : _enemy;
    Entity* second = my_attack_speed >= enemy_attack_speed ? _enemy : this;
    
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

void Entity::ShowSkills(const std::string _title, const std::size_t _index)
{
    std::cout << '\n' << _title;
    for (std::size_t i = 0; i < MAX_SKILL_COUNT; i++)
    {
        if (i % (MAX_SKILL_COUNT / 2) == 0)
            std::cout << '\n';
        
        if (_index == i)
            std::cout << "<<" << skills[i] << ">> ";
        else
            std::cout << skills[i] << " ";
    }
}

Skill* Entity::SelectSkill(const std::string _title)
{
    char input;
    std::size_t index = 0;

    ShowSkills(_title);
    while (true)
    {
        INPUT_KEY(input)
        if (!input)
            break;
        
        if (IF_CLOSE_KEY(input)) { return nullptr; }
        if (IF_UP_KEY(input)) { index += MAX_SKILL_COUNT / 2; }
        if (IF_DOWN_KEY(input)) { index -= MAX_SKILL_COUNT / 2; }
        if (IF_LEFT_KEY(input)) { index--; }
        if (IF_RIGHT_KEY(input)) { index++; }
        index %= MAX_SKILL_COUNT;
        
        ShowSkills(_title, index);
    }

    return &skills[index];
}

void Entity::AddSkill(Skill _skill)
{
    if (skill_count >= MAX_SKILL_COUNT) { ChangeSkill(_skill); }
    else { skills[skill_count++] = _skill; }
}

void Entity::ChangeSkill(Skill _new_skill)
{
    std::string title = "새로운 스킬: " + _new_skill.GetName();
    Skill* old_skill = SelectSkill(title);

    if (old_skill != nullptr)
    {
        std::cout << *old_skill << "이 " << _new_skill << "로 변경 되었습니다.\n";
        *old_skill = _new_skill;
    }
    else
    {
        std::cout << "스킬 변경이 취소 되었습니다.\n";
    }
}