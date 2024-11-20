#ifndef _ENUM_CLASS_
#define _ENUM_CLASS_

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

enum class EntityJob
{
    None,
    Warrior,
    Archer,
    Wizard,
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

#endif