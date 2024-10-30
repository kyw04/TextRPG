#pragma once
#include <map>
#include <string>
#include "EnumClass.hpp"
#include "Item/Item.hpp"

class Inventory
{
private:
    std::map<std::string, Item*> items;

public:
    void ShowInventory();
    void Push(Item*);
    Item* Pop(std::string);
};