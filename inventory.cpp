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

    int add_count;
    if (_count > _item->max_count)
    {
        add_count = _item->max_count;
        _count -= _item->max_count;
    }
    else
    {
        add_count = _count;
        _count = 0;
    }

    if (item_iter == items.end()) 
    {
        // 아이템으로 받아서 문제가 있어 보임
        // 현제 아이템 종류를 클래스로 만들었는데 나중에 함수 사용을 못할 것 같음
        Item* new_item = new Item(_item);
        new_item->count = add_count;
        items.insert({ item_name, new_item });
    }
    else 
    {
        add_count += item_iter->second->count;
        if (add_count > _item->max_count)
        {
            item_iter->second->count = _item->max_count;
            _count += add_count - _item->max_count;
            tag_iter->second->count++;
        }
        else { item_iter->second->count = add_count; }
    }

    Push(_item, _count);
}

Item* Inventory::Pop(const std::string _key)
{
    std::map<std::string, Item*>::iterator it = items.find(_key);
    if (it != items.end())
    {
        items.erase(it);
        return it->second;
    }
    else { return nullptr; }
}