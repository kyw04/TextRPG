#pragma once
#include <map>
#include <string>
#include "EnumClass.hpp"
#include "Item/Item.hpp"
#define IF_UP_KEY(_input) (_input == 'w' || _input == 'W')
#define IF_DOWN_KEY(_input) (_input == 's' || _input == 'S')
#define IF_CLOSE_KEY(_input) (_input == 'q' || _input == 'Q')

class Inventory
{
private:
    bool is_open;
    short size;
    std::map<std::string, Item*> items;

public:
    friend std::ostream& operator<<(std::ostream&, Inventory&);
    Inventory() : is_open(false), size(255) {}

    void Open();
    void Close();
    std::map<std::string, Item*> GetItems() const;
    void Push(Item*, int = 1);
    Item* Pop(const std::string);
    void Select(const char);
};