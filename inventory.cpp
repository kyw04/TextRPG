#include <iostream>
#include "./Header/Inventory.hpp"

void Inventory::ShowInventory()
{
    if (items.size() == 0)
    {
        std::cout << "비어있음.\n";
        return;
    }

    for (auto item : items)
    {
        std::cout << item.first << '\n';
    }
}

void Inventory::Push(Item* _item)
{
    if (items.find(_item->name) == items.end())
        items.insert({_item->name, _item});
}

Item* Inventory::Pop(std::string _key)
{
    if (items.find(_key) != items.end())
        return items.find(_key)->second;
    else 
        return nullptr;
}