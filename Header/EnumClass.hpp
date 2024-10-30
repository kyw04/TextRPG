#ifndef _ENUM_CLASS_
#define _ENUM_CLASS_

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
    Accessory, // 부속품
    Consumable, // 소모품
    Equipment, // 장비
    Weapon, // 무기
};

enum class ItemState
{
    Unequipped,
    Equipped,
};

enum class ItemRank
{
    None,
    Normal,
    Rare,
    Unique,
    Legendary
};

#endif