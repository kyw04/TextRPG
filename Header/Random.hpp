#pragma once
#include <vector>
#include <random>

template<typename T>
class RandomItem
{
public:
    T item;
    double percent;
    bool is_duplicate;

    RandomItem(T _item, double _percent = 0.0, bool _is_duplicate = false) : item(_item), percent(_percent), is_duplicate(_is_duplicate) { } 
};

template<typename T>
class Random
{
private:
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<> dis;

    std::vector<RandomItem<T>> duplicate_items;
    std::vector<RandomItem<T>> one_items;
    double total_percent;

public:
    // Random& operator=(std::vector<RandomItem<T>>& _items)
    // {
    //     for (RandomItem<T>& itm : _items)
    //         Push(itm);
        
    //     return *this;
    // }

    Random() { }
    Random(std::vector<RandomItem<T>> _items)
    {
        total_percent = 0;
        for (auto& itm : _items)
        {
            Push(itm);
        }
    }

    void Push(RandomItem<T> _item)
    {
        if (_item.is_duplicate)
            duplicate_items.push_back(_item);
        else
        {
            total_percent += _item.percent;
            one_items.push_back(_item);
        }
    }

    std::vector<T> GetRandomItems()
    {

        if (one_items.empty() && duplicate_items.empty())
            throw std::logic_error("item is empty");
        
        std::vector<T> result;

        for (auto& itm : duplicate_items)
        {
            double random_value = dis(gen);
            if (itm.percent >= random_value)
            {
                result.push_back(itm.item);
            }
        }

        double random_value = dis(gen);
        double sum = 0;
        for (auto& itm : one_items)
        {
            sum += itm.percent;
            if (sum / total_percent >= random_value)
            {
                result.push_back(itm.item);
                break;
            }
        }

        return result;
    }
};