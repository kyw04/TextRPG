#include "Header/Item/Item.hpp"

bool Item::operator==(const Item& _itm) const { return this->name == _itm.name; }

std::ostream& operator<<(std::ostream& _out, const Item& _itm)
{
    std::cout << _itm.name;
    
    return _out;
}

Item::Item(Item* _item) : max_count(_item->max_count)
{
    state = ItemState::Unequipped;
    category = _item->category;
    name = _item->name;
    count = _item->count;

    level_requirement = _item->level_requirement;
    job_requirement = _item->job_requirement;
    rank = _item->rank;
    stats = _item->stats;
}

std::string Item::GetInformation()
{
    std::string result = name + "\n";
    
    result.append("").append(GetEnumToString<EntityJob>(job_requirement)).append("\n");

    if (max_count < 1)
        result += std::to_string(count) + "\n";
    

    return result;
}