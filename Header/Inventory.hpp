#pragma once
#include <map>
#include <string>
#include "Entity/Entity.hpp"
#include "EnumClass.hpp"
#include "Item/Item.hpp"
#include "Define.hpp"

class Inventory
{
private:
    Entity* player;
    bool is_open;
    short size;
    std::map<std::string, Item*> items;
    std::map<ItemCategory, Item*> equipped_items;

public:

    friend std::ostream& operator<<(std::ostream&, Inventory&);
    Inventory(Entity* _player) : player(_player), is_open(false), size(255) {}

    void Open();
    void Close();
    std::map<std::string, Item*> GetItems() const;
    void Push(Item*, const int = 1); // 인풋아웃풋 관련 클래스 만들어서 관리
    Item* Pop(const std::string); // 인풋아웃풋 관련 클래스 만들어서 관리
    Item* Select(const char); // 인풋아웃풋 관련 클래스 만들어서 관리

    void Equip(Item*);
    void Unequip(Item*);
};