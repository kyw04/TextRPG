#ifndef _ENUM_CLASS_
#define _ENUM_CLASS_
#include <string>
#include <map>
#include <type_traits>

template<typename T>
struct EnumFlag
{
    T value;
    
    EnumFlag() : value(static_cast<T>(0)) { }
    EnumFlag(T _ref) : value(_ref) { }

    EnumFlag& operator=(const T& _ref)
    {
        this->value = _ref;
        return *this;
    }
    EnumFlag& operator=(const int& _ref)
    {
        this->value = static_cast<T>(_ref);
        return *this;
    }
    EnumFlag& operator|=(const T& _ref)
    {
        this->value = (int)this->value | (int)_ref;
    }

    bool operator==(const T& _ref) { return (this->value == _ref) || ((int)this->value & (int)_ref); }
    bool operator==(const EnumFlag& _ref) { return (this->value == _ref->value) || ((int)this->value & (int)_ref->value); }
    bool operator!=(const T& _ref)
    {
        if (this->value == _ref)
            return false;
        
        return !((int)this->value & (int)_ref);
    }
    bool operator!=(const EnumFlag& _ref)
    {
        if (this->value == _ref.value)
            return false;
        
        return !((int)this->value & (int)_ref.value);
    }
    
    bool operator<(const T& _ref) const { return (int)this->value < (int)_ref; }
    bool operator<(const EnumFlag& _ref) const { return (int)this->value < (int)_ref.value; }
    bool operator<=(const T& _ref) const { return (int)this->value <= (int)_ref; }
    bool operator<=(const EnumFlag& _ref) const { return (int)this->value <= (int)_ref.value; }
    bool operator>(const T& _ref) const { return (int)this->value > (int)_ref; }
    bool operator>(const EnumFlag& _ref) const { return (int)this->value > (int)_ref.value; }
    bool operator>=(const T& _ref) const { return (int)this->value >= (int)_ref; }
    bool operator>=(const EnumFlag& _ref) const { return (int)this->value >= (int)_ref.value; }
};

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
inline const std::map<StatsName, std::string> stats_name_string 
{
    { StatsName::Health, "체력" },
    { StatsName::MaxHealth, "최대 체력" },
    { StatsName:: Mana, "마나" },
    { StatsName:: MaxMana, "최대 마나" },

    { StatsName:: Strength, "물리 공격력" },
    { StatsName:: Intelligence, "마법 공격력" },
    { StatsName:: AttackSpeed, "공격 속도" },
    { StatsName:: Critical, "크리티컬" },

    { StatsName:: StrengthDefensive, "물리 방어력" },
    { StatsName:: IntelligenceDefensive, "마법 방어력" },

    { StatsName:: Level, "레벨" },
    { StatsName:: Experience, "경험치" },
    { StatsName:: NextExperience, "필요 경험치" },
};

enum class EntityJobEnum
{
    None = 0,
    Warrior = 1,
    Archer = 1 << 2,
    Wizard = 1 << 3,

    All = -1
};
inline const std::map<EntityJobEnum, std::string> entity_job_string
{
    { EntityJobEnum::Warrior, "전사" },
    { EntityJobEnum::Archer, "궁수" },
    { EntityJobEnum::Wizard, "마법사" },
    { EntityJobEnum::All, "모든" }
};

struct EntityJob : EnumFlag<EntityJobEnum>
{
    using EnumFlag<EntityJobEnum>::operator=;
    using EnumFlag<EntityJobEnum>::operator|=;

    using EnumFlag<EntityJobEnum>::operator==;
    using EnumFlag<EntityJobEnum>::operator!=;

    using EnumFlag<EntityJobEnum>::operator<;
};

enum class AttackType
{
    None,
    Strength,
    Intelligence
};
inline const std::map<AttackType, std::string> attack_type_string
{
    { AttackType::Strength, "물리" },
    { AttackType::Intelligence, "마법" }
};

enum class ItemCategoryEnum
{
    None = 0,
    Accessory = 1 << 0,
    Consumable = 1 << 1,
    Equipment = 1 << 2,

    Helmet = 1 << 3,
    Armor = 1 << 4,
    Leggings = 1 << 5,
    Shoes = 1 << 6,
    Weapon = 1 << 7,
};
inline const std::map<ItemCategoryEnum, std::string> item_category_enum_string
{
    { ItemCategoryEnum::Accessory, "부속품" },
    { ItemCategoryEnum::Consumable, "소모품" },
    { ItemCategoryEnum::Equipment, "장비" },

    { ItemCategoryEnum::Helmet, "투구" },
    { ItemCategoryEnum::Armor, "갑옷" },
    { ItemCategoryEnum::Leggings, "레깅스" },
    { ItemCategoryEnum::Shoes, "신발" },
    { ItemCategoryEnum::Weapon, "무기" }
};

struct ItemCategory : EnumFlag<ItemCategoryEnum>
{
    using EnumFlag<ItemCategoryEnum>::operator=;
    using EnumFlag<ItemCategoryEnum>::operator|=;

    using EnumFlag<ItemCategoryEnum>::operator==;
    using EnumFlag<ItemCategoryEnum>::operator!=;

    using EnumFlag<ItemCategoryEnum>::operator<;
};


enum class ItemState
{
    Unequipped,
    Equipped,
    CoolDown,
};
inline const std::map<ItemState, std::string> item_state_string
{
    { ItemState::Unequipped, "장착 안됨" },
    { ItemState::Equipped, "장착 됨" },
    { ItemState::CoolDown, "쿨타임" }
};

enum class ItemRank
{
    None,
    Normal,
    Rare,
    Unique,
    Legendary
};
inline const std::map<ItemRank, std::string> item_rank_string
{
    { ItemRank::Normal, "일반" },
    { ItemRank::Rare, "고급" },
    { ItemRank::Unique, "희귀" },
    { ItemRank::Legendary, "전설" }
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
inline const std::map<T, std::string> GetSearchMap()
{
    throw std::out_of_range("do not found enum to string map");
}
template<> inline const std::map<StatsName, std::string> GetSearchMap<StatsName>() { return stats_name_string; }
template<> inline const std::map<EntityJobEnum, std::string> GetSearchMap<EntityJobEnum>() { return entity_job_string; }
template<> inline const std::map<AttackType, std::string> GetSearchMap<AttackType>() { return attack_type_string; }
template<> inline const std::map<ItemState, std::string> GetSearchMap<ItemState>() { return item_state_string; }
template<> inline const std::map<ItemRank, std::string> GetSearchMap<ItemRank>() { return item_rank_string; }
template<> inline const std::map<ItemCategoryEnum, std::string> GetSearchMap<ItemCategoryEnum>() { return item_category_enum_string; }

// template<typename T>
// struct IsParentEnumFlag
// {
//     static constexpr bool value = 
//         std::is_base_of_v<EnumFlag<ItemCategoryEnum>, T>;
//         // || std::is_base_of_v<EnumFlag< >, T>;
// };
template<typename T>
inline std::string EnumFlagToString(EnumFlag<T> _enum)
{
    std::string str;
    int value = (int)_enum.value;
    int index = 0;
    int bit = 1 << index;
    while (value >= bit)
    {
        if (value & bit)
        {
            str.append(EnumToString(static_cast<T>(bit))).append(" ");
        }
        bit = (1 << ++index);
    }
    
    return str;
}

template<typename T>
inline std::string EnumToString(T _enum)
{
    const std::map<T, std::string>& search_map = GetSearchMap<T>();
    return search_map.find(_enum) == search_map.end() 
            ? throw std::overflow_error("do not found enum string") 
            : search_map.find(_enum)->second;
}

// add EnumFlag class
template<> inline std::string EnumToString(ItemCategory _enum) { return EnumFlagToString(_enum); }
template<> inline std::string EnumToString(EntityJob _enum) { return EnumFlagToString(_enum); }

#endif // _ENUM_CLASS_