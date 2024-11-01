#pragma once
#include <set>
#include "EnumClass.hpp"
#include "Item/Item.hpp"

class Inventory
{
private:
    short size;
    std::set<Item*> items;

public:
    friend std::ostream& operator<<(std::ostream&, const Inventory&);
    Inventory() : size(255) {}

    std::set<Item*> GetItems() const;
    void Push(Item*);
    Item* Pop(Item*);
};