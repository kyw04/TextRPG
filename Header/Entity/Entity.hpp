#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include "../Inventory.hpp"
#include "../Stats.hpp"
#include "../Item/Item.hpp"
#include "../EnumClass.hpp"
#include "../Define.hpp"
#include "../Skill/Skill.hpp"

class Entity : public Inventory
{
protected:
    bool is_die;
    Skill skills[MAX_SKILL_COUNT];
    std::size_t skill_count;

    Stats start_stats;

    void Die(Entity* _slayer);

public:
    std::string name;
    EntityJob job;
    AttackType attack_type;
   
    Stats equipped_item_total_stats;
    Stats stats;

    float drop_experience;
    std::vector<Item*> drop_items;

    Entity();
    virtual ~Entity() { };

    void StatsUpdate();
    void TakeDamage(Entity*, AttackType, float);
    void Fight(Entity&);
    bool IsDie();
    void ShowSkills(const std::string, const std::size_t = 0);
    Skill* SelectSkill(const std::string = ""); // 인풋아웃풋 관련 클래스 만들어서 관리
    void AddSkill(Skill); // 인풋아웃풋 관련 클래스 만들어서 관리
    void ChangeSkill(Skill);

    void Equip(Item*);
    void Unequip(Item*);
};