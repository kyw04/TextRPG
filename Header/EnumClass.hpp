#ifndef _ENUM_CLASS_
#define _ENUM_CLASS_
#include <string>
#include <map>

enum class StatsName
{
    Health,
    MaxHealth,
    Mana,
    MaxMana,

    Strength,
    Intelligence,
    AttackSpeed,
    Critical,

    StrengthDefensive,
    IntelligenceDefensive,

    Level,
    Experience,
    NextExperience,
};
inline const std::map<StatsName, const char*> stats_name_string 
{
    { StatsName::Health, "체력" },
    { StatsName::MaxHealth, "최대 체력" },
    { StatsName:: Mana, "마나" },
    { StatsName:: MaxMana, "최대 마나" },

    { StatsName:: Strength, "물리" },
    { StatsName:: Intelligence, "마법" },
    { StatsName:: AttackSpeed, "공격 속도" },
    { StatsName:: Critical, "크리티컬" },

    { StatsName:: StrengthDefensive, "물리 방어력" },
    { StatsName:: IntelligenceDefensive, "마법 방어력" },

    { StatsName:: Level, "레벨" },
    { StatsName:: Experience, "경험치" },
    { StatsName:: NextExperience, "필요 경험치" },
};

enum class EntityJob
{
    None,
    Warrior,
    Archer,
    Wizard,
};
inline const std::map<EntityJob, const char*> entity_job_string
{
    { EntityJob::Warrior, "전사" },
    { EntityJob::Archer, "궁수" },
    { EntityJob::Wizard, "마법사" }
};

enum class AttackType
{
    None,
    Strength,
    Intelligence
};

enum class ItemCategory
{
    None,
    Accessory, // 부속품
    Consumable, // 소모품
    Equipment, // 장비
    Weapon, // 무기
};

enum class ItemState
{
    Unequipped,
    Equipped,
    CoolDown,
};

enum class ItemRank
{
    None,
    Normal,
    Rare,
    Unique,
    Legendary
};

enum class InventoryItemState
{
    None,
    Selected,
};

enum class TileState
{
    Wall,
    Empty,
    Monster,
    Boss,
    Treasure,
    Trap,
    None // 개수 카운트용으로 마지막에 배치
};

template<typename T>
inline const std::map<T, const char*> GetSearchMap()
{
    throw "do not found enum to string map";
}
template<> inline const std::map<StatsName, const char*> GetSearchMap<StatsName>() { return stats_name_string; }
template<> inline const std::map<EntityJob, const char*> GetSearchMap<EntityJob>() { return entity_job_string; }

template<typename T>
inline const char* GetEnumToString(T _enum)
{
    const std::map<T, const char*>& search_map = GetSearchMap<T>();
    
    return search_map.find(_enum) == search_map.end() ? "" : search_map.find(_enum)->second;
}

#endif // _ENUM_CLASS_