#include "./Header/Inventory.hpp"


void Inventory::Open() 
{ 
    std::cout << "인벤토리 열림\n";
    is_open = true;
    
    char input;
    while (is_open)
    {
        input = (char)getchar();
        if (input == '\n')
            continue;
        
        if (items.empty() || IF_CLOSE_KEY(input))
        {
            Close();
            break;
        }
        
        this->Select(input);
        std::cout << *this;
    }
}
void Inventory::Close() 
{
    std::cout << "인벤토리 닫힘\n";
    is_open = false;
}

std::map<std::string, Item*> Inventory::GetItems() const
{
    return this->items;
}

std::ostream& operator<<(std::ostream& _out, Inventory& _inven)
{
    if (_inven.GetItems().empty())
    {
        std::cout << "비어있음.\n";
        _inven.Close();
    }
    else
    {
        for (auto item : _inven.GetItems())
        {
            if (item.second->category != ItemCategory::None) 
            { 
                if (item.second->inventory_item_state == InventoryItemState::Selected)
                    std::cout << "<<" << item.first << " " << *item.second << ">>\n";
                else
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

void Inventory::Select(const char _input)
{
    if (!is_open || IF_CLOSE_KEY(_input)) { Close(); return; }

    static int index = -1;
    if (IF_UP_KEY(_input)) { index += 1; }
    else if (IF_DOWN_KEY(_input)) { index += -1; }

    int count = 0;
    int max_index = 0;
    std::map<std::string, Item *>::iterator selected_iter = items.end();
    std::map<std::string, Item *>::iterator first_iter = items.end();    
    std::map<std::string, Item *>::iterator last_iter = items.end();    
    std::map<std::string, Item *>::iterator iter;
    for (iter = items.begin(); iter != items.end(); iter++) 
    {
        while (iter == items.end() || iter->second->category == ItemCategory::None)
        {
            if (iter == items.end()) { iter = items.begin(); }
            else { iter++; max_index++; }
        }

        if (first_iter == items.end())
            first_iter = iter;
        last_iter = iter;
        iter->second->inventory_item_state = InventoryItemState::None;
        if (index == count)
            selected_iter = iter;
        count++;
    }
    max_index = (int)items.size() - max_index - 1;
    if (index <= 0) { selected_iter = first_iter; index = 0; }
    if (max_index <= index) { selected_iter = last_iter; index = max_index; }
    selected_iter->second->inventory_item_state = InventoryItemState::Selected;
}