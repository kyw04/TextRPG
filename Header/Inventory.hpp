#pragma once
#include <map>
#include <string>
#include "EnumClass.hpp"
#include "Item/Item.hpp"

class Inventory
{
private:
    short size;
    std::map<std::string, Item*> items;

public:
    friend std::ostream& operator<<(std::ostream&, const Inventory&);
    Inventory() : size(255) {}

    std::map<std::string, Item*> GetItems() const;
    void Push(Item*, int = 1);
    Item* Pop(const std::string);
};