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
            if (item.second->category != ItemCategory::None) 
            { 
                std::cout << item.first << " " << *item.second << '\n';
            }
        }
    }
    return _out;
}

void Inventory::Push(Item* _item, int _count)
{
    if (_count <= 0)
        return;
    
    std::map<std::string, Item*>::iterator tag_iter = items.find(_item->name);
    if (tag_iter == items.end()) { tag_iter = items.insert({ _item->name, new Item() }).first; }

    std::string item_name = _item->name + "(" + std::to_string(tag_iter->second->count) + ")"; 
    std::map<std::string, Item*>::iterator item_iter = items.find(item_name);
    _item->count = _count > _item->max_count ? _item->max_count : _count;
    if (item_iter == items.end()) 
    {
        items.insert({ item_name, _item });
    }
    else 
    {
        int add_count = _item->count + item_iter->second->count;
        _count += (add_count - _item->max_count) <= 0 ? 0 : (add_count - _item->max_count);
        item_iter->second->count = add_count > _item->max_count ? _item->max_count : add_count;
    }

    if (_count - _item->max_count >= 0)
    {
        tag_iter->second->count++;
        Push(_item, _count - _item->max_count);
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