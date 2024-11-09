#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include "../Stats.hpp"
#include "../Item/Item.hpp"
#include "../EnumClass.hpp"
#include "../Define.hpp"
#include "../Skill/Skill.hpp"

class Entity
{
protected:
    bool is_die;
    Skill skills[MAX_SKILL_COUNT];
    std::size_t skill_count;

    void virtual Die();

public:
    std::string name;
    EntityJob job;
    AttackType attack_type;
    Stats *stats;

    Entity();
    void TakeDamage(AttackType, float);
    void Fight(Entity*);
    bool IsDie();
    Skill& SelectSkill();
    void AddSkill(Skill);
    void ChangeSkill(Skill);
};