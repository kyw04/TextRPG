#include <iostream>
#include "./Header/Entity/Entity.hpp"

Entity::Entity() : is_die(false), level(1), experience(0), next_experience(100)
{
}
Entity::Entity(std::string _name) : is_die(false), level(1), experience(0), next_experience(100), name(_name)
{
}


void Entity::LevelUP()
{
    std::cout << "== 레벨 업 " << level << " >> " << level + 1 << " ==\n";
    std::cout << "== 스텟 포인트 3 획득 " << stats_point << " >> " << stats_point  + 3 << " ==\n";

    level++;
    stats_point += 3;
    experience = experience - next_experience;
    next_experience = float(level * (level + 1)) * 25.0f - 50.0f;
}

void Entity::StatsUpdate()
{
    if (!stats.IsEmpty())
    {
        float health = stats.GetStats<float>(StatsName::Health);
        float max_health = stats.GetStats<float>(StatsName::MaxHealth);
        float mana = stats.GetStats<float>(StatsName::Mana);
        float max_mana = stats.GetStats<float>(StatsName::MaxMana);

        stats = start_stats + equipped_item_total_stats + allocated_stats;
        stats.SetStats<float>(StatsName::Health, max_health * (health / max_health));
        stats.SetStats<float>(StatsName::Mana, max_mana * (mana / max_mana));
    }
    else
        stats = start_stats + equipped_item_total_stats + allocated_stats;
}

void Entity::SetExperience(float _value)
{
    experience = _value;

    if (_value >= next_experience)
    {
        LevelUP();
    }
}

void Entity::AddExperience(float _value)
{
    SetExperience(experience + _value);
}

void Entity::ShowAllocatedStats(int _selected_index)
{
    for (int i = 0; i < allocated_stats_size; i++)
    {
        float value = allocated_stats.GetStats<float>(allocated_stats_names[i]);
        std::string stat_name = EnumToString(allocated_stats_names[i]);
        if (i == _selected_index)
            std::cout << "<<" << stat_name << ": " << value << ">>\n";
        else
            std::cout << stat_name << ": " << value << "\n";
    }
    std::cout << "\n스텟 포인트: " << stats_point << "\n";
}

void Entity::AddStat(float _value)
{
    int input;
    int index = 0;

    ShowAllocatedStats(index);
    do
    {
        input = INPUT_KEY();
        if (IS_UP_KEY(input))
        {
            index = (index - 1) < 0 ? allocated_stats_size - 1 : index - 1;
        }
        if (IS_DOWN_KEY(input))
        {
            index = (index + 1) % allocated_stats_size;
        }
        if (IS_CLOSE_KEY(input))
        {
            return;
        }
        ShowAllocatedStats(index);
    } while (!IS_ENTER_KEY(input));

    if (stats_point <= 0)
    {
        std::cout << "스텟 포인트가 부족합니다.\n\n";
        while (!IS_ENTER_KEY(INPUT_KEY())) { }
        return;
    }

    stats_point--;
    StatsName selected_name = allocated_stats_names[index];
    if (selected_name == StatsName::MaxHealth) { _value *= 10; }
    if (selected_name == StatsName::MaxMana) { _value *= 25; }
    if (selected_name == StatsName::Critical) { _value *= 0.01f; }
    
    float current_value = allocated_stats.GetStats<float>(selected_name);
    allocated_stats.SetStats(selected_name, current_value + _value);

    std::cout << "추가 " << EnumToString(allocated_stats_names[index]) << ": " << current_value << " >> " << current_value + _value << "\n\n";
    StatsUpdate();
    while (!IS_ENTER_KEY(INPUT_KEY())) { }
    AddStat();
}

void Entity::TakeDamage(Entity* _attacker, float _value)
{
    stats.AddHealth(_value);

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
    std::cout << damage << "의 데미지를 입혔습니다.\n";
    _defender->TakeDamage(_attacker, damage * _defender->stats.DefencePercent(_attacker->attack_type));
}

void Entity::Fight(Entity& _enemy)
{
    float my_attack_speed = stats.GetStats<float>(StatsName::AttackSpeed);
    float enemy_attack_speed = _enemy.stats.GetStats<float>(StatsName::AttackSpeed);
    Entity* first = my_attack_speed >= enemy_attack_speed ? this : &_enemy;
    Entity* second = my_attack_speed >= enemy_attack_speed ? &_enemy : this;

    while (!IS_ENTER_KEY(INPUT_KEY())) { }     
    Attack(first, second);

    if (!second->IsDie())
    {
        std::cout << this->name;
        this->stats.ShowHealth();
        std::cout << _enemy.name;
        _enemy.stats.ShowHealth();

        while (!IS_ENTER_KEY(INPUT_KEY())) { }
        Attack(second, first);
        if (!first->IsDie())
        {
            std::cout << this->name;
            this->stats.ShowHealth();
            std::cout << _enemy.name;
            _enemy.stats.ShowHealth();
        }
    }
}

void Entity::Die(Entity* _slayer)
{
    is_die = true;
    std::cout << name << "(이)가 죽었습니다.\n";
    
    while (!IS_ENTER_KEY(INPUT_KEY())) { }

    std::cout << "=================\n";
    for (auto& drop_item : drop_items.GetRandomItems())
    {
        _slayer->Push(drop_item);
    }

    std::cout << "경험치 " << drop_experience << "획득\n\n";
    _slayer->AddExperience(drop_experience);
    while (!IS_ENTER_KEY(INPUT_KEY())) { }
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
    int input;
    std::size_t index = 0;

    ShowSkills(_title);
    while (true)
    {
        input = INPUT_KEY();
        if (IS_ENTER_KEY(input))
            break;
        
        if (IS_CLOSE_KEY(input)) { return nullptr; }
        if (IS_UP_KEY(input)) { index += MAX_SKILL_COUNT / 2; }
        if (IS_DOWN_KEY(input)) { index -= MAX_SKILL_COUNT / 2; }
        if (IS_LEFT_KEY(input)) { index--; }
        if (IS_RIGHT_KEY(input)) { index++; }
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
        _item->level_requirement > level)
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