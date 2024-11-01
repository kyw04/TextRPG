#include "Header/Item/Item.hpp"

bool Item::operator==(const Item& _itm) const { return this->name == _itm.name; }

std::ostream& operator<<(std::ostream& _out, const Item& _itm)
{
    std::cout << _itm.name << " : " << _itm.count;
    return _out;
}