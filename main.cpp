#include <iostream>
#include "./Header/Stats.h"

int main()
{
    Stats stats;
    stats.ShowStats();
    stats.TakeDamage(10);
    std::cout << std::endl;
    stats.ShowStats();
    
    return 0;
}