#include "./Header/Inventory.hpp"

std::set<Item*> Inventory::GetItems() const
{
    return this->items;
}

std::ostream& operator<<(std::ostream& _out, const Inventory& _inven)
{
    if (_inven.GetItems().size() == 0)
    {
        std::cout << "비어있음.\n";
    }
    else
    {
        for (auto item : _inven.GetItems())
        {
            std::cout << *item << '\n';
        }
    }
    return _out;
}

void Inventory::Push(Item* _item)
{
    std::set<Item*>::iterator it = items.find(_item);
    if (it == items.end())
    {
        items.insert(_item);
    }
    else
    {
        if ((*it)->category == ItemCategory::Accessory && (*it)->max_count > (*it)->count)
        {
            (*it)->count++;
        }
    }
}

Item* Inventory::Pop(Item* _key)
{
    std::set<Item*>::iterator it = items.find(_key);
    if (it != items.end())
        return *it;
    else 
        return nullptr;
}