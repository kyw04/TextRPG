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
#include "../Random.hpp"

inline const int allocated_stats_size = 6;
inline StatsName allocated_stats_names[allocated_stats_size] = 
{
    StatsName::MaxHealth,
    StatsName::MaxMana,
    StatsName::Strength,
    StatsName::Intelligence,
    StatsName::AttackSpeed,
    StatsName::Critical
};

class Entity : public Inventory
{
protected:
    bool is_die;
    Skill skills[MAX_SKILL_COUNT];
    std::size_t skill_count;

    Stats start_stats;

    void virtual Die(Entity* _slayer);
    void LevelUP();

public:
    int level;
    float experience;
    float next_experience;

    std::string name;
    EntityJob job;
    AttackType attack_type;
   
    int stats_point;
    Stats allocated_stats;
    Stats equipped_item_total_stats;
    Stats stats;

    float drop_experience;
    Random<Item*> drop_items;

    Entity();
    virtual ~Entity() { }

    void StatsUpdate();
    void SetExperience(float);
    void AddExperience(float);
    void ShowAllocatedStats(int = allocated_stats_size);
    void AddStat(float = 1.0f);
    void TakeDamage(Entity*, float);
    void Fight(Entity&);
    bool IsDie();
    void ShowSkills(const std::string, const std::size_t = 0);
    Skill* SelectSkill(const std::string = ""); // 인풋아웃풋 관련 클래스 만들어서 관리
    void AddSkill(Skill); // 인풋아웃풋 관련 클래스 만들어서 관리
    void ChangeSkill(Skill);

    void Equip(Item*);
    void Unequip(Item*);
};