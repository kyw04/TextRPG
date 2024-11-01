#include "./Header/Inventory.hpp"

std::map<std::string, Item*> Inventory::GetItems() const
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
            std::cout << *item.second << '\n';
        }
    }
    return _out;
}

void Inventory::Push(Item* _item, const int _count)
{
    std::map<std::string, Item*>::iterator it = items.find(_item->name);
    if (it == items.end())
    {
        _item->count = _count;
        items.insert({_item->name, _item});
    }
    else
    {
        Item* itm = it->second;
        if ((itm->category == ItemCategory::Accessory || itm->category == ItemCategory::Consumable)
            && itm->max_count > itm->count)
        {
            itm->count += _count;
        }
        else
        {
            
        }
    }
}

Item* Inventory::Pop(const std::string _key)
{
    std::map<std::string, Item*>::iterator it = items.find(_key);
    if (it != items.end())
        return it->second;
    else 
        return nullptr;
}