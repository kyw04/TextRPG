#include <iostream>
#include "./Header/Entity/Entity.hpp"

Entity::Entity() : is_die(false)
{
}

void Entity::StatsUpdate()
{
    stats = start_stats + equipped_item_total_stats;
}

void Entity::TakeDamage(Entity* _attacker, AttackType _attack_type, float _value)
{
    stats.AddHealth(stats.GetDamage(_attack_type, _value));

    if (stats.GetStats<float>(StatsName::Health) <= 0) { Die(_attacker); }
}

void Attack(Entity* _attacker, Entity* _defender)
{
    float damage;
    switch (_attacker->attack_type)
    {
    case AttackType::None:
        break;
    case AttackType::Strength:
        damage = _attacker->stats.GetStats<float>(StatsName::Strength);
        break; 
    case AttackType::Intelligence:
        damage = _attacker->stats.GetStats<float>(StatsName::Intelligence); 
        break;
    }

    std::cout << _attacker->name << "의 공격\n";
    std::cout << _defender->name << "에게 ";
    std::cout << damage << "의 데미지를 입힘\n";
    _defender->TakeDamage(_attacker, _attacker->attack_type, damage);
    if (!_defender->IsDie())
        std::cout << _defender->name << " 체력: " << _defender->stats.GetStats<float>(StatsName::Health) << '\n';
}

void Entity::Fight(Entity& _enemy)
{
    float my_attack_speed = stats.GetStats<float>(StatsName::AttackSpeed);
    float enemy_attack_speed = _enemy.stats.GetStats<float>(StatsName::AttackSpeed);
    Entity* first = my_attack_speed >= enemy_attack_speed ? this : &_enemy;
    Entity* second = my_attack_speed >= enemy_attack_speed ? &_enemy : this;

    char input;
    INPUT_KEY(input);        
    Attack(first, second);

    if (!IF_DOWN_KEY(input)) INPUT_KEY(input);
    if (!second->IsDie()) Attack(second, first);
}

void Entity::Die(Entity* _slayer)
{
    is_die = true;

    for (auto& drop_item : drop_items)
        _slayer->Push(drop_item, drop_item->count);
    _slayer->stats.AddExperience(drop_experience);

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

void Entity::Equip(Item* _item)
{
    if (_item->job_requirement != job ||
        _item->level_requirement > stats.GetStats<int>(StatsName::Level))
    {
        std::cout << "조건을 충족하지 않아 착용할 수 없습니다.\n";
        return;
    }

    std::map<ItemCategory, Item*>::iterator found_iter = equipped_items.find(_item->category);
    if (found_iter != equipped_items.end())
    {
        Unequip(found_iter->second);
    }

    _item->state = ItemState::Equipped;
    equipped_items.insert({ _item->category, _item });
    equipped_item_total_stats += _item->stats;
    std::cout << _item->name << "이 장착 되었습니다.\n";
}
void Entity::Unequip(Item* _item)
{
    _item->state = ItemState::Unequipped;
    equipped_items.erase(_item->category);
    equipped_item_total_stats -= _item->stats;
    std::cout << _item->name << "이 해제 되었습니다.\n";
}