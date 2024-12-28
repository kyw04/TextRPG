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
    std::string result;
    result.clear();
    result.append("분류: ").append(EnumToString(category)).append("\n");
    result.append("등급: ").append(EnumToString(rank)).append("\n");
    result.append("이름: ").append(name).append("\n");
    result.append("------------------\n");
    
    if (category == ItemCategoryEnum::Equipment)
    {
        result.append(EnumToString(state)).append("\n");
        result.append("직업: ").append(EnumToString(job_requirement)).append("\n");
        result.append("레벨: ").append(std::to_string(level_requirement)).append("Lv\n");
        result.append("------------------\n");
        result.append(stats->GetAllStatsToString());
    }
    else
    {
        result += std::to_string(count) + "\n";
    }
    result.append("\n");

    return result;
}